#include <bits/stdc++.h>
using namespace std;
int dp[25][25][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  dp[0][0][0] = 1, dp[0][0][1] = 1, dp[0][0][2] = 1, dp[0][0][3] = 1;
  dp[1][0][1] = 1, dp[1][0][2] = 2, dp[1][0][3] = 3;
  for (int i = 2; i < n; i++) {
    for (int t = 0; t < n; t++) {
      for (int cv = 0; cv < 4; cv++) {
        for (int pv = 0; pv < 4; pv++) {
          if (cv == pv) continue;
          if (t & 1) {
            if (cv < pv) {
              dp[i][t][cv] += dp[i - 1][t][pv];
            } else {
              dp[i][t + 1][cv] += dp[i - 1][t][pv];
            }
          } else {
            if (cv > pv) {
              dp[i][t][cv] += dp[i - 1][t][pv];
            } else {
              dp[i][t + 1][cv] += dp[i - 1][t][pv];
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += dp[n - 1][2 * k - 1][i];
  }
  cout << ans << '\n';
  return 0;
}
