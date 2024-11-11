#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
const long long maxn = 200005;
long long n, m, g, inv[maxn], fac[maxn], ans;
inline long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % p;
    x = (x % p * x % p);
    y >>= 1;
  }
  return res;
}
inline long long C(long long x, long long y) {
  return fac[x] % p * inv[y] % p * inv[x - y] % p;
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &g);
  if (!n) {
    printf("%lld", m == 1 ? g : g ^ 1);
    return 0;
  }
  if (!m) {
    printf("%lld", n % 2 == 1 ? g ^ 1 : g);
    return 0;
  }
  fac[0] = fac[1] = 1;
  for (long long i = 2; i <= n + m; i++) fac[i] = (fac[i - 1] * i) % p;
  inv[n + m] = qpow(fac[n + m], p - 2);
  for (long long i = n + m - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % p;
  if (g) {
    for (long long i = 1; i <= n; i += 2)
      ans = (ans + C(n + m - i - 1, m - 1)) % p;
    if (m == 1) {
      if (n & 1)
        ans = (ans - 1 + p) % p;
      else
        ans = (ans + 1) % p;
    }
  } else {
    for (long long i = 0; i <= n; i += 2)
      ans = (ans + C(n + m - 1 - i, m - 1)) % p;
    if (m == 1) {
      if (n & 1)
        ans = (ans + 1) % p;
      else
        ans = (ans - 1 + p) % p;
    }
  }
  printf("%lld", ans);
  return 0;
}
