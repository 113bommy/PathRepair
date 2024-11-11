#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<string> v(2);
  cin >> v[0] >> v[1];
  int64_t n = v[0].length();
  int64_t dp[n + 1][4];
  memset(dp, 0, sizeof(dp));
  for (int64_t i = 2; i <= n; i++) {
    dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1], dp[i][2] = dp[i - 1][2],
    dp[i][3] = dp[i - 1][3];
    if (v[0][i - 1] == '0' && v[0][i - 2] == '0' && v[1][i - 2] == '0') {
      dp[i][0] =
          max(dp[i][0],
              1 + max(dp[i - 2][0],
                      max(dp[i - 2][1], max(dp[i - 2][2], dp[i - 2][3]))));
    }
    if (v[0][i - 1] == '0' && v[1][i - 1] == '0' && v[0][i - 2] == '0') {
      dp[i][1] = max(dp[i][1], dp[i - 1][3]);
      dp[i][1] =
          max(dp[i][1],
              1 + max(dp[i - 2][0],
                      max(dp[i - 2][1], max(dp[i - 2][2], dp[i - 2][3]))));
    }
    if (v[0][i - 1] == '0' && v[1][i - 1] == '0' && v[1][i - 2] == '0') {
      dp[i][2] = max(dp[i][2], dp[i - 1][0]);
      dp[i][2] =
          max(dp[i][2],
              1 + max(dp[i - 2][0],
                      max(dp[i - 2][1], max(dp[i - 2][2], dp[i - 2][3]))));
    }
    if (v[1][i - 1] == '0' && v[0][i - 2] == '0' && v[1][i - 2] == '0') {
      dp[i][3] =
          max(dp[i][3],
              1 + max(dp[i - 2][0],
                      max(dp[i - 2][1], max(dp[i - 2][2], dp[i - 2][3]))));
    }
  }
  int64_t ans = max(dp[n][0], max(dp[n][1], max(dp[n][2], dp[n][3])));
  cout << ans << "\n";
  return 0;
}
