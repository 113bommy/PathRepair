#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  int dp[30][5][11][2];
  for (int i = 1; i <= 4; ++i) {
    dp[1][i][1][1] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= t; ++j) {
      for (int now = 1; now <= 4; ++now) {
        for (int pre = 1; pre <= 4; ++pre) {
          if (now > pre) {
            dp[i][now][j][1] += dp[i - 1][pre][j - 1][0] + dp[i - 1][pre][j][1];
          }
          if (pre > now) {
            dp[i][now][j][0] += dp[i - 1][pre][j][0] + dp[i - 1][pre][j][1];
          }
          if (i == 2) {
            dp[i][now][j][0] = 0;
          }
        }
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= 4; ++i) {
    sum += dp[n][i][t][0];
  }
  cout << sum << '\n';
  return 0;
}
