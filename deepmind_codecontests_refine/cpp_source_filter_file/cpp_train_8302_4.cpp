#include <bits/stdc++.h>
#pragma optimize(3, "Ofast", "inline")
using namespace std;
const long long maxn = 1e6 + 10, mod = 998244353;
long long fac[maxn], inv[maxn];
inline long long quick_pow(long long base, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) (ret *= base) %= mod;
    (base *= base) %= mod, b >>= 1;
  }
  return ret;
}
inline long long C(long long x, long long y) {
  return fac[x] * inv[y] % mod * inv[x - y];
}
signed main() {
  long long n, ans = 0, tmp = 0;
  scanf("%lld", &n);
  fac[0] = 1;
  inv[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = quick_pow(fac[i], mod - 2);
  }
  for (long long i = 1; i <= n; i++)
    (ans +=
     2 * quick_pow(3, n * (n - i) + i) * quick_pow(-1, i + 1) * C(n, i) % mod +
     mod) %= mod;
  for (long long i = 0; i < n; i++) {
    long long t = -quick_pow(3, i);
    (ans += 3 *
            (C(n, i) * quick_pow(-1, i + 1) *
                 (quick_pow(1 + t, n) - quick_pow(t, n) + mod) % mod +
             mod) %
            mod) %= mod;
  }
  cout << ans;
}
