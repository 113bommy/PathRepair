#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    long long a00 = a[0][0];
    long long ans = INF;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        long long need = a[x][y] - x - y;
        if (need > a00) continue;
        a[0][0] = need;
        vector<vector<long long>> dp(n, vector<long long>(m, INF));
        dp[0][0] = a00 - need;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            long long need = a[0][0] + i + j;
            if (need > a[i][j]) continue;
            if (i > 0) {
              dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j] - need);
            }
            if (j > 0) {
              dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j] - need);
            }
          }
        }
        ans = min(ans, dp[n - 1][m - 1]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
