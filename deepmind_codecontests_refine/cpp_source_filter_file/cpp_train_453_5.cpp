#include <bits/stdc++.h>
const int maxn = 2005, mod = 1000000007;
int n, m, ans;
int f[maxn][maxn], sum[maxn][maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= m; i++) f[1][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      f[i][j] = (1ll * f[i - 1][j] + 2ll * f[i][j - 1] % mod -
                 1ll * f[i][j - 2] + mod) %
                mod;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++) sum[i][j] = sum[i - 1][j] + f[i][j];
  for (int i = 1; i <= n; i++)
    for (int k = 2; k <= m; k++)
      ans =
          (ans + 1ll * f[i][k] * sum[n - i + 1][k] % mod * (m - k + 1) % mod) %
          mod;
  printf("%d\n", ans);
  return 0;
}
