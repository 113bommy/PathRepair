#include <bits/stdc++.h>
using namespace std;
long long a[105][105], dp[105][105], n, m, res;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int nTest = 0;
  cin >> nTest;
  while (nTest--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) cin >> a[i][j];
    long long st = a[1][1];
    res = LLONG_MAX;
    for (int x = 1; x <= n; ++x)
      for (int y = 1; y <= m; ++y) {
        a[1][1] = a[x][y] - x - y + 2;
        if (a[1][1] > st) continue;
        for (int i = 0; i <= n; ++i)
          for (int j = 0; j <= m; ++j) dp[i][j] = 1e16;
        dp[1][1] = st - a[1][1];
        for (int i = 1; i <= n; ++i)
          for (int j = 1; j <= m; ++j) {
            long long step = a[i][j] - (a[1][1] + i + j - 2);
            if (step >= 0)
              dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + step);
          }
        res = min(res, dp[n][m]);
      }
    cout << res << "\n";
  }
  return 0;
}
