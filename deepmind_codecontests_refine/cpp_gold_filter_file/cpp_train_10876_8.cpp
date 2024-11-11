#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 2;
const int INF = 0x3f3f3f3f;
int n, k;
int dp[maxn][200][5];
void DP() {
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 1; j <= k; j++) {
      int flag = 1;
      if (j != 1 && j != k) flag = 2;
      dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][3]) - flag * x;
      dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j][0]);
      dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + flag * x;
      dp[i][j][3] = max(dp[i - 1][j][3], dp[i][j][2]);
      if (flag == 2) {
        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][1]);
        dp[i][j][3] = max(dp[i][j][3], dp[i - 1][j - 1][3]);
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++)
    for (int j = 0; j <= 3; j++) dp[0][i][j] = -INF;
  DP();
  printf("%d", max(dp[n][k][1], dp[n][k][3]));
  return 0;
}
