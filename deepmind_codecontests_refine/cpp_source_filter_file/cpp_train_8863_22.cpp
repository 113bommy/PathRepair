#include <bits/stdc++.h>
const long long mod = 998244353;
long long n, m, l, dp[4010][2010][2], fac[4010];
long long quickpow(long long x, long long y) {
  if (y == 0) return 1;
  if (y % 2 == 0) return quickpow(x * x % mod, y / 2);
  return quickpow(x * x % mod, y / 2) * x % mod;
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &l);
  dp[0][0][0] = 1;
  for (long long i = 0; i <= 2 * n; i++)
    for (long long j = 0; j <= i; j++)
      for (long long o = 0; o <= 1; o++) {
        (dp[i + 1][j + 1][o] += dp[i][j][o]) %= mod;
        if (j >= m && !o) (dp[i + 1][j][1] += dp[i][j][0]);
        if (j) (dp[i + 1][j - 1][o] += dp[i][j][o] * j % mod) %= mod;
      }
  long long ans = dp[2 * n + 1][0][1];
  fac[0] = 1;
  for (long long i = 1; i <= 2 * n + 1; i++) fac[i] = fac[i - 1] * i % mod;
  (ans *= quickpow(2, n) * fac[n] % mod * quickpow(fac[n * 2 + 1], mod - 2) %
          mod * l % mod) %= mod;
  printf("%lld\n", ans);
}
