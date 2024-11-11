#include <bits/stdc++.h>
using namespace std;
int n, m, a[50000][10], dp[50000][10], i, j;
int main() {
  scanf("%d %d", &m, &n);
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  dp[1][1] = a[1][1];
  for (i = 2; i <= m; i++) dp[i][1] = dp[i - 1][1] + a[i][1];
  for (i = 2; i <= n; i++) dp[1][i] = dp[1][i - 1] + a[1][i];
  for (j = 2; j <= n; j++)
    for (i = 2; i <= m; i++)
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
  for (i = 1; i <= m; i++) printf("%d ", dp[i][n]);
  return 0;
}
