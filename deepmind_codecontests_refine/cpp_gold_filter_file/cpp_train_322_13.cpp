#include <bits/stdc++.h>
namespace my_std {
using namespace std;
const long long INF = 0x7fffffff;
inline long long read() {
  long long sum = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    f |= (c == '-');
    c = getchar();
  }
  while (isdigit(c)) {
    sum = (sum << 1) + (sum << 3) + (c ^ 48);
    c = getchar();
  }
  return f ? -sum : sum;
}
void write(long long k) {
  if (k < 0) putchar('-'), k = -k;
  if (k >= 10) write(k / 10);
  putchar(k % 10 + '0');
}
inline void chkmax(long long &x, long long y) {
  if (x < y) x = y;
}
inline void chkmin(long long &x, long long y) {
  if (x > y) x = y;
}
}  // namespace my_std
using namespace my_std;
const long long N = 100010;
const long long mod = 998244353;
long long s, r, p, fac[N], _fac[N];
inline long long quick_pow(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * x % mod;
    k >>= 1;
    x = x * x % mod;
  }
  return res;
}
inline long long inv(long long x) { return quick_pow(x, mod - 2); }
inline void pre(long long n) {
  fac[0] = _fac[0] = 1;
  for (register long long i = (1); i <= (n); i++) fac[i] = fac[i - 1] * i % mod;
  for (register long long i = (1); i <= (n); i++) _fac[i] = inv(fac[i]);
}
inline long long C(long long n, long long m) {
  if (n < m || m < 0) return 0;
  return fac[n] % mod * _fac[m] % mod * _fac[n - m] % mod;
}
inline void inc(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void dec(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
inline long long ABS(long long x) { return (x % mod + mod) % mod; }
inline long long solve(long long n, long long m, long long s) {
  long long sum = 0;
  for (register long long i = (0); i <= (m); i++) {
    if (i * s > n) break;
    long long res = ABS(C(m, i) * C(n - i * s - 1 + m, m - 1));
    i & 1 ? dec(sum, res) : inc(sum, res);
  }
  return ABS(sum);
}
signed main() {
  p = read(), s = read(), r = read();
  pre(10000);
  long long ans = 0;
  for (register long long k = (r); k <= (s); k++) {
    if (k * p - s < 0) continue;
    for (register long long i = (1); i <= (p); i++) {
      if (i * k - s > 0) continue;
      if ((k - 1) * (p - i) + i * k - s < 0) continue;
      if (i != p)
        inc(ans,
            ABS(ABS(C(p - 1, i - 1) * solve(s - i * k, p - i, k)) * inv(i)));
      else if (i * k == s)
        inc(ans, ABS(inv(i)));
      ans = ABS(ans);
    }
  }
  write(ABS(ans * inv(C(s - r + p - 1, p - 1)))), putchar('\n');
  return 0;
}
