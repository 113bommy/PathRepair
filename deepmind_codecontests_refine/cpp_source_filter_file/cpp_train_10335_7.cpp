#include <bits/stdc++.h>
using namespace std;
int n, m, mod;
int l[1000010], sum[1000010];
long long mul[5010];
int f[5010][5010];
long long g[10000010], dp[1000010];
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  int maxn = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
    maxn = max(maxn, l[i]);
    sum[i] = (sum[i - 1] + l[i]);
  }
  f[0][0] = 1;
  mul[0] = 1;
  for (int i = 1; i <= maxn; i++) {
    mul[i] = (mul[i - 1] * i) % mod;
    for (int j = 1; j <= maxn; j++) {
      f[i][j] = (f[i - 1][j - 1] + (j - 1ll) * f[i - 1][j] % mod) % mod;
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    long long C = 1;
    for (int j = 1; j <= l[i]; j++) {
      C = (C * (m - j + 1)) % mod;
      if (!f[l[i]][j]) continue;
      if (j > l[i - 1]) {
        g[sum[i - 1] + j] = C * f[l[i]][j] % mod * dp[i - 1] % mod;
      } else {
        g[sum[i - 1] + j] =
            (C * f[l[i]][j] * dp[i - 1] % mod -
             f[l[i]][j] * g[sum[i - 2] + j] % mod * mul[j] % mod + mod) %
            mod;
      }
      dp[i] = (dp[i] + g[sum[i - 1] + j]) % mod;
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}
