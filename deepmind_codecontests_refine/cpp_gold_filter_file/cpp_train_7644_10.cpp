#include <bits/stdc++.h>
using namespace std;
int dp[4][1005][1005], a[1005][1005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i][j + 1]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j - 1]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j + 1]) + a[i][j];
    }
  }
  int ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 2; j <= m - 1; j++) {
      int left1 = dp[0][i][j - 1];
      int up1 = dp[0][i - 1][j];
      int left2 = dp[2][i][j - 1];
      int up2 = dp[2][i + 1][j];
      int right1 = dp[3][i][j + 1];
      int down1 = dp[3][i + 1][j];
      int right2 = dp[1][i][j + 1];
      int down2 = dp[1][i - 1][j];
      ans = max(ans, left1 + up2 + right1 + down2);
      ans = max(ans, left2 + up1 + right2 + down1);
    }
  }
  printf("%d\n", ans);
}
