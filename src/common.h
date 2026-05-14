#ifndef TSVC_COMMON_HDR
#define TSVC_COMMON_HDR

#ifndef iterations
#define iterations 100000
#endif
#ifndef LEN_1D
#define LEN_1D 32000
#endif
#ifndef LEN_2D
#define LEN_2D 256
#endif

#include <sys/time.h>
#include <stdint.h>

struct args_t {
    struct timeval t1;
    struct timeval t2;
    void * __restrict__ arg_info;
};

// Floating point types (ascending width, default f32)
#if defined(USE_FLOAT16)
typedef _Float16 real_t;        // f16  (16-bit)
#define ABS fabsf
#elif defined(USE_DOUBLE)
typedef double real_t;          // f64  (64-bit)
#define ABS fabs
// Integer types (ascending width)
#elif defined(USE_INT8)
typedef int8_t real_t;          // i8   (8-bit)
#define ABS abs
#elif defined(USE_INT16)
typedef int16_t real_t;         // i16  (16-bit)
#define ABS abs
#elif defined(USE_INT)
typedef int real_t;             // i32  (32-bit)
#define ABS abs
#else
typedef float real_t;           // f32  (32-bit, default)
#define ABS fabsf
#endif

int dummy(real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_1D], real_t[LEN_2D][LEN_2D], real_t[LEN_2D][LEN_2D], real_t[LEN_2D][LEN_2D], real_t);

void init(int** ip, real_t* s1, real_t* s2);

int initialise_arrays(const char* name);
real_t calc_checksum(const char * name);

#endif
