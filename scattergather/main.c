/**
 * Accomplishes scatter gather io, reads from the standard input into a vector of buffers, and it writes out the contents of the vectors 
 * to the standard output
 * */
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_OF_BUFFERS 5
#define SIZE_OF_BUFFERS 5
int main()
{
    char *buffers[NUM_OF_BUFFERS];
    struct iovec vectors[NUM_OF_BUFFERS];
    for (size_t i = 0; i < NUM_OF_BUFFERS; i++)
    {
        buffers[i] = calloc(SIZE_OF_BUFFERS, sizeof(char));
        vectors[i].iov_base = buffers[i];
        vectors[i].iov_len = SIZE_OF_BUFFERS;
    }
    readv(STDIN_FILENO, vectors, NUM_OF_BUFFERS);

    writev(STDOUT_FILENO, vectors, NUM_OF_BUFFERS);

    for (size_t i = 0; i < NUM_OF_BUFFERS; ++i)
    {
        free(buffers[i]);
    }
}