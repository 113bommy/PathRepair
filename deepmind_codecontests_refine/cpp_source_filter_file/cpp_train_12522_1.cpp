#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    int n, m;
    string s1, s2;
    cin >> n >> m >> s1 >> s2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 2;
          ans = max(ans, dp[i][j]);
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
