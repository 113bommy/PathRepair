#include <bits/stdc++.h>
namespace std {
long long abs(long long x) { return x < 0 ? -x : x; }
}  // namespace std
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
    int N;
    scanf("%d", &N);
    int nt = 0;
    int sol = oo;
    vector<int> cnt(2 * N + 1, 0);
    char t[1024];
    scanf("%s", t);
    for (int i = 0; i < N; ++i) {
      if (t[i] == 'T') {
        ++nt;
        cnt[i + 1] = cnt[i + N + 1] = 1;
      }
    }
    for (int i = 1; i <= 2 * N; ++i) {
      cnt[i] += cnt[i - 1];
    }
    int nh = N - nt;
    for (int i = 1; i <= N; ++i) {
      int have = cnt[i + nt - 1] - cnt[i - 1];
      sol = min(sol, nt - have);
    }
    printf("%d\n", sol);
    return 0;
  } catch (const Exception& exception) {
    fprintf(stderr, "******************************\n");
    fprintf(stderr, "ERROR.%d: %s\n", exception.line, exception.message);
    fprintf(stderr, "******************************\n");
    throw exception;
  }
}
