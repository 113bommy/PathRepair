#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int dp[25][5][10][2];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int j = 1; j <= 4; j++) dp[1][j][0][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int k = 1; k <= t; k++) {
      for (int j = 1; j <= 4; j++) {
        for (int pre = 1; pre <= 4; pre++) {
          if (pre > j) {
            dp[i][j][k][1] += dp[i - 1][pre][k][0];
            dp[i][j][k][1] += dp[i - 1][pre][k][1];
          } else if (pre < j) {
            dp[i][j][k][0] += dp[i - 1][pre][k - 1][1];
            dp[i][j][k][0] += dp[i - 1][pre][k][0];
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= 4; i++) ans += dp[n][i][t][1];
  printf("%d\n", ans);
  return 0;
}
