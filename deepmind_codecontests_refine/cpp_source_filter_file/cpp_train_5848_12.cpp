#include <bits/stdc++.h>
long long f[55][2505];
long long F[55][55][2505];
long long dp[55][55][55][5], mo = 1000000007, fac[55];
int cnt[5], t[55], g[55];
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &t[i], &g[i]), cnt[g[i]]++, fac[i] = fac[i - 1] * i % mo;
  f[0][0] = F[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (g[i] == 1)
      for (int j = T - t[i]; j >= 0; j--)
        for (int k = cnt[1]; k >= 0; k--)
          f[k + 1][j + t[i]] = (f[k + 1][j + t[i]] + f[k][j]) % mo;
    else {
      for (int j = T - t[i]; j >= 0; j--)
        for (int k = cnt[2]; k >= 0; k--)
          for (int p = cnt[3]; p >= 0; p--) {
            if (g[i] == 2)
              F[k + 1][p][j + t[i]] = (F[k + 1][p][j + t[i]] + F[k][p][j]) % mo;
            if (g[i] == 3)
              F[k][p + 1][j + t[i]] = (F[k][p + 1][j + t[i]] + F[k][p][j]) % mo;
          }
    }
  }
  dp[0][0][1][2] = 1;
  dp[0][1][0][1] = 1;
  dp[1][0][0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        if (i + j + k == 1) continue;
        if (k)
          dp[i][j][k][2] =
              (dp[i][j][k][2] + dp[i][j][k - 1][1] + dp[i][j][k - 1][0]) % mo;
        if (j)
          dp[i][j][k][1] =
              (dp[i][j][k][1] + dp[i][j - 1][k][2] + dp[i][j - 1][k][0]) % mo;
        if (i)
          dp[i][j][k][0] =
              (dp[i][j][k][0] + dp[i - 1][j][k][1] + dp[i - 1][j][k][2]) % mo;
      }
  long long ans = 0;
  for (int i = 0; i <= cnt[1]; i++)
    for (int j = 0; j <= cnt[2]; j++)
      for (int k = 0; k <= cnt[3]; k++)
        for (int p = 0; p <= T; p++)
          ans = (ans + (dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2]) % mo *
                           f[i][p] * F[j][k][T - p] % mo * fac[i] % mo *
                           fac[j] % mo * fac[k] % mo) %
                mo;
  printf("%lld\n", ans);
}
