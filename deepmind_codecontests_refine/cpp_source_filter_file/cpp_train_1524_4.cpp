#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const long long p = 998244353;
long long qp(long long x, long long y) {
  long long res = 1;
  for (long long t = x; y; y >>= 1, t = t * t % p)
    if (y & 1) res = res * t % p;
  return res;
}
long long f[1000003], g[1000003], fac[1000003], ifac[1000003];
signed main() {
  fac[0] = ifac[0] = 1;
  long long n = read(), k = read();
  for (long long i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % p;
  ifac[n] = qp(fac[n], p - 2);
  for (long long i = n - 1; i >= 1; --i) ifac[i] = ifac[i + 1] * (i + 1) % p;
  f[0] = 1, g[0] = 1;
  for (long long i = 1; i <= n; ++i)
    f[i] =
        (g[i - 1] + p - (i - k - 1 >= 0 ? g[i - k - 1] : 0)) * fac[i - 1] % p,
    g[i] = (g[i - 1] + f[i] * ifac[i] % p) % p;
  long long ans = fac[n];
  for (long long i = 1; i <= n; ++i)
    ans = (ans + p - f[i - 1] * fac[n - 1] % p * ifac[i - 1] % p) % p;
  printf("%lld\n", ans);
  return 0;
}
