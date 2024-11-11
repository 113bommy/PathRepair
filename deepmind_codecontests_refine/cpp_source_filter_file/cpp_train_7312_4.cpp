#include <bits/stdc++.h>
using namespace std;
long long a[110][110];
long long dp[110][110];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  long long res = 0x3f3f3f3f3f3f3f;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          dp[i][j] = 0x3f3f3f3f3f3f3f;
        }
      }
      dp[x][y] = 0;
      for (int i = x; i >= 1; i--) {
        for (int j = y; j >= 1; j--) {
          long long cur = a[x][y] - (x - i + y - j);
          long long cost = a[i][j] - cur;
          if (cost >= 0) {
            if (i + 1 <= n) {
              dp[i][j] = min(dp[i][j], dp[i + 1][j] + cost);
            }
            if (j + 1 <= m) {
              dp[i][j] = min(dp[i][j], dp[i][j + 1] + cost);
            }
          }
        }
      }
      for (int i = x; i <= n; i++) {
        for (int j = y; j <= m; j++) {
          long long cur = a[x][y] + i - x + j - y;
          long long cost = a[i][j] - cur;
          if (cost >= 0) {
            if (i - 1 >= x) {
              dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost);
            }
            if (j - 1 >= y) dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost);
          }
        }
      }
      if (dp[1][1] != 0x3f3f3f3f3f3f3f && dp[n][m] != 0x3f3f3f3f3f3f3f)
        res = min(res, dp[1][1] + dp[n][m]);
    }
  }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
