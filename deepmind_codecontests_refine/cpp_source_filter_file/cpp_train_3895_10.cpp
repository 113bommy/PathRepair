#include <bits/stdc++.h>
template <typename T>
void rd(T& x) {
  long long f = 0, c;
  while ((c = getchar()) < 48 || 57 < c) f ^= !(c ^ 45);
  x = (c & 15);
  while (47 < (c = getchar()) && c < 58) x = x * 10 + (c & 15);
  if (f) x = -x;
}
template <typename T>
inline void pt(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) pt(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void pt(T x, long long c) {
  pt(x), putchar(c);
}
template <typename T>
inline T max(const T& x, const T& y) {
  return x < y ? y : x;
}
template <typename T>
inline T min(const T& x, const T& y) {
  return x < y ? x : y;
}
long long solve(long long a, long long n, long long p) {
  long long t = a * n / p;
  if (!t) return max(a, p - a * n);
  return solve(a - p % a, t - (a * n % p < p / a - 1), a);
}
signed main() {
  long long T;
  rd(T);
  while (T--) {
    long long a, n, p, h;
    rd(a), rd(n), rd(p), rd(h), a %= p;
    puts((a * n < p ? a : solve(a, n, p)) <= h ? "YES" : "NO");
  }
  return 0;
}
