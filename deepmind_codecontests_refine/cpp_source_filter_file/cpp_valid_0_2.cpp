#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  long long f = 0;
  x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  if (f) x = -x;
}
const long long N = 1e6 + 5, mod = 1e9 + 7;
long long n, q, f[N][3], p[N * 3], in[N * 3];
long long qpow(long long x, long long y) {
  long long t = 1;
  while (y) {
    if (y & 1) t = t * x % mod;
    x = x * x % mod, y >>= 1;
  }
  return t;
}
long long C(long long x, long long y) {
  return p[x] * in[y] % mod * in[x - y] % mod;
}
void prework() {
  p[0] = 1;
  for (long long i = 1; i <= 3 * n; ++i) p[i] = p[i - 1] * i % mod;
  in[3 * n] = qpow(p[3 * n], mod - 2);
  for (long long i = 3 * n; i >= 1; --i) in[i - 1] = in[i] * i % mod;
  f[0][0] = f[0][1] = f[0][2] = n;
  for (long long i = 1, inv = qpow(3, mod - 2); i <= n; ++i) {
    f[i][0] = C(3 * n, i + 1) - f[i - 1][0] * 2 - f[i - 1][1];
    f[i][0] = (f[i][0] % mod + mod) % mod;
    (f[i][0] *= inv) %= mod;
    f[i][1] = (f[i][0] + f[i - 1][0]) % mod;
    f[i][2] = (f[i][1] + f[i - 1][1]) % mod;
  }
}
signed main() {
  read(n), read(q);
  prework();
  for (long long i = 1, x; i <= q; ++i)
    read(x), printf("%lld\n", (f[x][0] + C(3 * n, x)) % mod);
}
