#include <bits/stdc++.h>
template <typename T>
void print(T x) {}
template <>
void print<int>(int x) {
  printf("%d", x);
}
template <>
void print<const int>(const int x) {
  printf("%d", x);
}
template <>
void print<long long>(long long x) {
  printf("%lld", x);
}
template <>
void print<const long long>(const long long x) {
  printf("%lld", x);
}
template <>
void print<char>(char x) {
  putchar(x);
}
template <>
void print<const char>(const char x) {
  putchar(x);
}
template <>
void print<double>(double x) {
  printf("%.12lf", x);
}
template <typename T, typename... qwq>
void print(T x, qwq... args) {
  print(x);
  print(args...);
}
template <typename T, typename... qwq>
void debug(T x, qwq... args) {}
const long long mod = 1000000007;
inline long long read() {
  long long num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline long long re1d() {
  char c = getchar();
  while (c < 32 || c > 127) c = getchar();
  return c == '?' ? -1 : c - 48;
}
inline long long min(long long a, long long b) { return a > b ? b : a; }
inline long long max(long long a, long long b) { return a < b ? b : a; }
long long a[1000005], b[1000005], ways_d[2005][4005], dp_d[2005][4005],
    *ways[2005], *dp[2005];
void dA(long long &a, long long b) { a = (a + b) % mod; }
long long Abs(long long xs) { return xs > 0 ? xs : -xs; }
signed main() {
  long long T = read();
  for (long long i = 1; i <= (T); i++) {
    long long n = read();
    for (long long i = 1; i <= (n); i++) {
      a[i] = re1d();
      if (i & 1) a[i] = a[i] == -1 ? -1 : a[i] ^ 1;
    }
    for (long long i = 1; i <= (n); i++) {
      b[i] = re1d();
      if (i & 1) b[i] = b[i] == -1 ? -1 : b[i] ^ 1;
    }
    for (long long i = 0; i < (1 + n); i++)
      ways[i] = ways_d[i] + n, dp[i] = dp_d[i] + n;
    for (long long i = 1; i <= (n); i++) {
      for (long long j = -n; j <= n; j++) ways[i][j] = dp[i][j] = 0;
    }
    ways[0][0] = 1;
    for (long long i = 1; i <= (n); i++) {
      for (long long j = -i + 1; j <= i - 1; j++) {
        long long W = ways[i - 1][j], D = dp[i - 1][j];
        for (long long A = 0; A < 2; A++) {
          for (long long B = 0; B < 2; B++) {
            if ((A ^ 1) == a[i]) continue;
            if ((B ^ 1) == b[i]) continue;
            long long K = j + A - B;
            dA(ways[i][K], W);
            dA(dp[i][K], W * Abs(K) + D % mod);
          }
        }
      }
    }
    printf("%lld\n", dp[n][0]);
  }
  return 0;
}
