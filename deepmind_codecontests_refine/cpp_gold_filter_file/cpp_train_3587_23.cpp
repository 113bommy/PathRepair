#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000;
int a[1600][1600];
long long dp[1600][1600][2];
int main() {
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    a[i][0] = 0;
    for (j = 1; j <= m; j++) {
      scanf("%d ", &a[i][j]);
      a[i][j] += a[i][j - 1];
    }
  }
  for (i = 0; i <= n; i++)
    for (j = 0; j <= m + 1; j++) {
      if (i == 0) {
        dp[i][j][1] = 0;
        dp[i][j][0] = 0;
      } else {
        dp[i][j][0] = -inf;
        dp[i][j][1] = -inf;
      }
    }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      dp[i][j][0] = dp[i - 1][j - 1][1] + a[i][j];
      dp[i][j][1] = dp[i - 1][j + 1][0] + a[i][j];
    }
    for (j = 1; j <= m; j++) {
      dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1]);
    }
    for (j = m; j > 0; j--) {
      dp[i][j][0] = max(dp[i][j][0], dp[i][j + 1][0]);
    }
  }
  if (n % 2 == 1)
    printf("%I64d", dp[n][1][0]);
  else
    printf("%I64d", dp[n][m][1]);
}
