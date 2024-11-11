#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5, M = 20;
long long n, d, mod, dp[N][M][N], f[M], g[M], ans;
long long mul(long long x, long long n, long long mod) {
  long long ans = mod != 1;
  for (x %= mod; n; n >>= 1, x = x * x % mod)
    if (n & 1) ans = ans * x % mod;
  return ans;
}
void init() {
  long long n = 10;
  f[0] = g[0] = 1;
  for (long long i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
  g[n] = mul(f[n], mod - 2, mod);
  for (long long i = n - 1; i; i--) g[i] = g[i + 1] * (i + 1) % mod;
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  long long ans = 1;
  for (long long i = 1; i <= m; i++) ans = ans * (n - i + 1) % mod;
  return ans * g[m] % mod;
}
signed main() {
  scanf("%lld%lld%lld", &n, &d, &mod), init();
  if (n <= 2) puts("1"), exit(0);
  for (long long i = 0; i <= n; i++) dp[1][0][i] = 1;
  for (long long i = 2; i <= n; i++)
    for (long long j = 1; j <= min(i - 1, d); j++)
      for (long long k = 1; k <= n; k++) {
        dp[i][j][k] = dp[i][j][k - 1];
        for (long long t = 1; i - t * k > 0 && j - t >= 0; t++) {
          if (k != 1)
            dp[i][j][k] =
                (dp[i][j][k] + dp[i - t * k][j - t][k - 1] *
                                   C(dp[k][d - 1][k - 1] + t - 1, t) % mod) %
                mod;
          else
            dp[i][j][k] =
                (dp[i][j][k] + dp[i - t * k][j - t][k - 1] *
                                   C(dp[k][0][k - 1] + t - 1, t) % mod) %
                mod;
        }
      }
  if (n & 1)
    ans = dp[n][d][n / 2];
  else
    ans = (dp[n][d][n / 2] - C(dp[n / 2][d - 1][n / 2], 2) + mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
