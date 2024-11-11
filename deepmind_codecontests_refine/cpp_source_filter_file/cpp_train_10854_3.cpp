#include <bits/stdc++.h>
namespace Acc {
const long long N = 4e6 + 10;
const long long mod = 998244353;
long long inv[N], inv_fac[N], fac[N], n, m, p[N], pre, T, ans;
long long work() {
  scanf("%lld%lld", &n, &m);
  inv[0] = inv_fac[0] = fac[0] = inv[1] = fac[1] = inv_fac[1] = 1;
  for (long long i = 2; i <= n + m; i++) {
    inv[i] = 1ll * (mod - (mod / i)) * inv[mod % i] % mod;
    fac[i] = 1ll * fac[i - 1] * i % mod;
    inv_fac[i] = 1ll * inv[i] * inv_fac[i - 1] % mod;
  }
  for (long long i = 1; i <= n + 1; i++) {
    p[i] = 1ll * (1 - pre + mod) % mod * m % mod * inv[m + n - i + 1] % mod;
    pre = (pre + p[i]) % mod;
  }
  for (long long i = 1; i <= n + 1; i++) T = (T + 1ll * i * p[i] % mod) % mod;
  for (long long i = 1; i <= n; i++) {
    long long c = 1ll * fac[n] % mod * inv_fac[i] % mod * inv[n - i] % mod;
    long long frac = 1ll * (i + m) % mod * inv[i] % mod;
    ans =
        (ans + 1ll * (i & 1 ? 1 : mod - 1) * c % mod * frac % mod + mod) % mod;
  }
  printf("%lld", ans * T % mod);
  return 0;
}
}  // namespace Acc
signed main() { return Acc::work(); }
