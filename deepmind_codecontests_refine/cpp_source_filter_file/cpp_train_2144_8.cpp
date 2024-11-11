#include <bits/stdc++.h>
int t1, t2, t3;
int g[88][88];
int n, k;
int m;
int dp[88][88][88];
int ans = 0x3f3f3f3f;
int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("0");
    return 0;
  }
  scanf("%d", &m);
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      g[i][j] = 0x3f3f3f3f;
      for (int kk = 0; kk <= k; kk++) dp[i][j][kk] = 0x3f3f3f3f;
    }
  }
  while (m--) {
    scanf("%d%d%d", &t1, &t2, &t3);
    g[t1][t2] = (g[t1][t2] <= t3 ? g[t1][t2] : t3);
  }
  for (t1 = 1; t1 <= n; t1++) {
    for (t2 = 1; t2 <= n; t2++) {
      if (g[t1][t2] == 0x3f3f3f3f) continue;
      dp[t2][t1][1] = g[t1][t2];
      if (0 < t1 < t2)
        dp[t2][n + 1][1] =
            (dp[t2][n + 1][1] <= g[t1][t2] ? dp[t2][n + 1][1] : g[t1][t2]);
      else
        dp[t2][0][1] = (dp[t2][0][1] <= g[t1][t2] ? dp[t2][0][1] : g[t1][t2]);
    }
  }
  for (int diff = n; diff > 0; diff--) {
    for (int i = 1; i <= n; i++) {
      if (i + diff > n + 1) continue;
      for (int kk = 0; kk < k; kk++) {
        if (dp[i][i + diff][kk] == 0x3f3f3f3f) continue;
        for (int j = i + 1; j < i + diff; j++) {
          if (g[i][j] == 0x3f3f3f3f) continue;
          dp[j][i + diff][kk + 1] =
              (dp[j][i + diff][kk + 1] <= dp[i][i + diff][kk] + g[i][j]
                   ? dp[j][i + diff][kk + 1]
                   : dp[i][i + diff][kk] + g[i][j]);
          dp[j][i][kk + 1] = (dp[j][i][kk + 1] <= dp[i][i + diff][kk] + g[i][j]
                                  ? dp[j][i][kk + 1]
                                  : dp[i][i + diff][kk] + g[i][j]);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i - diff < 0) continue;
      for (int kk = 0; kk < k; kk++) {
        if (dp[i][i - diff][kk] == 0x3f3f3f3f) continue;
        for (int j = i - 1; j > i - diff; j--) {
          if (g[i][j] == 0x3f3f3f3f) continue;
          dp[j][i - diff][kk + 1] =
              (dp[j][i - diff][kk + 1] <= dp[i][i - diff][kk] + g[i][j]
                   ? dp[j][i - diff][kk + 1]
                   : dp[i][i - diff][kk] + g[i][j]);
          dp[j][i][kk + 1] = (dp[j][i][kk + 1] <= dp[i][i - diff][kk] + g[i][j]
                                  ? dp[j][i][kk + 1]
                                  : dp[i][i - diff][kk] + g[i][j]);
        }
      }
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (dp[i][j][k - 1]) {
        ans = (ans <= dp[i][j][k - 1] ? ans : dp[i][j][k - 1]);
      }
    }
  }
  if (ans == 0x3f3f3f3f)
    printf("-1");
  else
    printf("%d", ans);
}
