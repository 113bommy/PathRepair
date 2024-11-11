#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void in(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
  f ? x = -x : 0;
}
template <class T>
inline void out(T x, const char c = '\n') {
  static short st[30];
  short m = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++m] = x % 10, x /= 10;
  while (x);
  while (m) putchar(st[m--] | '0');
  putchar(c);
}
template <class T>
inline void err(const T &x, const char c = '\n') {
  cerr << x << c;
}
template <class T, class... Args>
inline void in(T &x, Args &...args) {
  in(x);
  in(args...);
}
template <class T, class... Args>
inline void out(const T &x, const Args &...args) {
  out(x, ' ');
  out(args...);
}
template <class T, class... Args>
inline void err(const T &x, const Args &...args) {
  err(x, ' ');
  err(args...);
}
template <class T>
inline void prt(T a[], int n) {
  for (register int i = 0; i < n; ++i) out(a[i], i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void clr(T a[], int n) {
  memset(a, 0, sizeof(T) * n);
}
template <class T>
inline void clr(T *a, T *b) {
  memset(a, 0, sizeof(T) * (b - a));
}
template <class T>
inline bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
namespace i207M {
long long calc(int a, int b, int c, long long s) {
  if (s & 1) return 0;
  static long long _dp[2][130][2];
  auto f = _dp[0], g = _dp[1];
  memset(f, 0, sizeof _dp[0]);
  f[0][0] = 1;
  for (register int i = 1; (1 << i) <= s; ++i) {
    swap(f, g);
    memset(f, 0, sizeof _dp[0]);
    for (register int j = 0; j <= a + b; ++j)
      for (register int k = 0; k <= 1; ++k) {
        if (!g[j][k]) continue;
        if (i < a && j < b && k == ((s >> i) & 1)) f[j + 2][1] += g[j][k];
        if (k == (((s >> i) & 1) ^ 1))
          f[j + 1][k == 1] += g[j][k] * ((i < a) + (j < b));
        if (k == ((s >> i) & 1)) f[j][0] += g[j][k];
      }
  }
  return f[c][0];
}
long long solve(long long s) {
  long long ans = 0;
  for (register int i = 0; (1ll << i) <= s; ++i)
    for (register int j = 0; (1ll << j) <= s; ++j) {
      long long x = s - (1ll << j) + 1;
      if (x < 0) continue;
      x = x / ((1ll << (i + 1)) + (1ll << (j + 1)) - 3);
      if (!x) continue;
      long long ns =
          s - (2 * x * ((1ll << i) - 1) + (2 * x + 1) * ((1ll << j) - 1) + x);
      for (register int k = 0, mk = max(i - 1, 0) + max(j - 1, 0); k <= mk; ++k)
        ans += calc(i, j, k, ns + k);
    }
  return ans;
}
signed main() {
  long long s;
  in(s);
  out(solve(s));
  return 0;
}
}  // namespace i207M
signed main() {
  i207M::main();
  return 0;
}
