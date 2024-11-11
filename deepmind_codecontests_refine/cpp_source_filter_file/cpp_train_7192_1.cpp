#include <bits/stdc++.h>
int dp[201][101][201], md = 1000000007;
int trs[201][2], ne[201];
char ch[201];
int main() {
  int n, m;
  scanf("%d%s", &n, ch);
  m = strlen(ch);
  trs[0][0] = trs[0][1] = 0;
  if (ch[0] == '(')
    trs[0][0] = 1;
  else
    trs[0][1] = 1;
  ne[0] = -1;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      int t = ne[i - 1];
      if (t == -1) {
        trs[i][j] = trs[0][j];
        ne[i] = 0;
      } else {
        ne[i] = trs[t][ch[i - 1] - '('];
        trs[i][j] = trs[ne[i]][j];
      }
      if (ch[i] == j + '(') trs[i][j] = i + 1;
    }
  }
  for (int i = n * 2; i >= 0; i--) {
    for (int j = 0; j <= i && j <= n; j++) {
      for (int k = 0; k <= m; k++) {
        if (i == n * 2) {
          if (j == 0 && k == m)
            dp[i][j][k] = 1;
          else
            dp[i][j][k] = 0;
          continue;
        }
        if (k == m) {
          dp[i][j][k] = dp[i + 1][j + 1][m];
          if (j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j - 1][m]) % md;
        } else {
          dp[i][j][k] = dp[i + 1][j + 1][trs[k][0]];
          if (j > 0)
            dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j - 1][trs[k][1]]) % md;
        }
      }
    }
  }
  printf("%d", dp[0][0][0]);
  return 0;
}
