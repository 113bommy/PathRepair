#include <bits/stdc++.h>
int a[66][66][66], dp[66][66][66];
int main() {
  int i, j, k, t, n, m, r;
  while (~scanf("%d%d%d", &n, &m, &r)) {
    for (k = 1; k <= m; k++) {
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) scanf("%d", &a[k][i][j]);
      }
    }
    for (k = 1; k <= m; k++) {
      for (t = 1; t <= n; t++) {
        for (i = 1; i <= n; i++) {
          for (j = 1; j <= n; j++)
            a[k][i][j] = ((a[k][i][j]) > (a[k][i][t] + a[k][t][j])
                              ? (a[k][i][t] + a[k][t][j])
                              : (a[k][i][j]));
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        dp[i][j][0] = a[1][i][j];
        for (k = 1; k <= m; k++)
          dp[i][j][0] =
              ((dp[i][j][0]) > (a[k][i][j]) ? (a[k][i][j]) : (dp[i][j][0]));
      }
    }
    for (k = 1; k <= n; k++) {
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
          dp[i][j][k] = dp[i][j][k - 1];
          for (t = 1; t <= n; t++)
            dp[i][j][k] = ((dp[i][j][k]) > (dp[i][t][k - 1] + dp[t][j][0])
                               ? (dp[i][t][k - 1] + dp[t][j][0])
                               : (dp[i][j][k]));
        }
      }
    }
    while (r--) {
      scanf("%d%d%d", &i, &j, &k);
      k = ((k) > (n) ? (n) : (k));
      printf("%d\n", dp[i][j][k]);
    }
  }
  return 0;
}
