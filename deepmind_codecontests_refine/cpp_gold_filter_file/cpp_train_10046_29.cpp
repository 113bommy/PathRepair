#include <bits/stdc++.h>
using namespace std;
void dprintf(char* format, ...) {
  fprintf(stderr, "DEBUG: ");
  va_list argp;
  va_start(argp, format);
  vfprintf(stderr, format, argp);
  va_end(argp);
  fprintf(stderr, "\n");
}
struct Exception {
  const char* message;
  const int line;
  Exception(const char* m, int l) : message(m), line(l) {}
};
static char stringReader[2097152];
static inline bool ReadLine() {
  char* ptr = fgets(stringReader, sizeof(stringReader), stdin);
  if (ptr == 0) return false;
  int N = strlen(stringReader);
  if (stringReader[N - 1] == '\n') stringReader[N - 1] = 0;
  return true;
}
const long long ooLL = 0x3f3f3f3f3f3f3f3fLL;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int main() {
  try {
    for (int N, x0, y0, x1, y1;
         scanf("%d%d%d%d%d", &N, &x0, &y0, &x1, &y1) == 5;) {
      if ((x0 == 0 && x1 == 0) || (x0 == N && x1 == N)) {
        printf("%d\n", abs(y1 - y0));
      } else if ((y0 == 0 && y1 == 0) || (y0 == N && y1 == N)) {
        printf("%d\n", abs(x1 - x0));
      } else {
        int d0[] = {oo, oo, oo, oo};
        int d1[] = {oo, oo, oo, oo};
        if (x0 == 0) {
          d0[0] = y0;
          d0[1] = N - y0;
          d0[2] = N + d0[1];
          d0[3] = N + d0[0];
        } else if (x0 == N) {
          d0[3] = y0;
          d0[2] = N - y0;
          d0[1] = N + d0[2];
          d0[0] = N + d0[3];
        } else if (y0 == N) {
          d0[1] = x0;
          d0[2] = N - x0;
          d0[0] = N + d0[1];
          d0[3] = N + d0[2];
        } else if (y0 == 0) {
          d0[0] = x0;
          d0[3] = N - x0;
          d0[1] = N + d0[0];
          d0[2] = N + d0[3];
        }
        if (x1 == 0) {
          d1[0] = y1;
          d1[1] = N - y1;
          d1[2] = N + d1[1];
          d1[3] = N + d1[0];
        } else if (x1 == N) {
          d1[3] = y1;
          d1[2] = N - y1;
          d1[1] = N + d1[2];
          d1[0] = N + d1[3];
        } else if (y1 == N) {
          d1[1] = x1;
          d1[2] = N - x1;
          d1[0] = N + d1[1];
          d1[3] = N + d1[2];
        } else if (y1 == 0) {
          d1[0] = x1;
          d1[3] = N - x1;
          d1[1] = N + d1[0];
          d1[2] = N + d1[3];
        }
        int d = oo;
        for (int i = 0; i < 4; ++i) d = min(d, d0[i] + d1[i]);
        printf("%d\n", d);
      }
    }
    return 0;
  } catch (const Exception& exception) {
    fprintf(stderr, "******************************\n");
    fprintf(stderr, "ERROR.%d: %s\n", exception.line, exception.message);
    fprintf(stderr, "******************************\n");
    throw exception;
  }
}
