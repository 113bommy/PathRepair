#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 30, INF = -2e9;
int n, k;
int dp[N][205][2][2];
int a[N];
int ps[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ps[i] = ps[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j][0][0] = INF;
      dp[i][j][0][1] = INF;
      dp[i][j][1][0] = INF;
      dp[i][j][1][1] = INF;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(i, k); ++j) {
      for (int d1 = 0; d1 < 2; ++d1) {
        for (int d2 = 0; d2 < 2; ++d2) {
          if (j == 1)
            dp[i][j][d1][d2] = max(dp[i][j][d1][d2],
                                   dp[i - 1][j][d1][d2] + (d1 ? a[i] : -a[i]));
          else if (i - 1)
            dp[i][j][d1][d2] = max(dp[i][j][d1][d2], dp[i - 1][j][d1][d2] +
                                                         (d1 ? a[i] : -a[i]) +
                                                         (d2 ? -a[i] : a[i]));
          if (i - 1) {
            for (int d3 = 0; d3 < 2; ++d3) {
              dp[i][j][d1][d2] =
                  max(dp[i][j][d1][d2], dp[i - 1][j - 1][d2][d3] +
                                            (d1 ? a[i] : -a[i]) +
                                            (j > 1) * (d2 ? -a[i] : a[i]));
            }
          }
        }
      }
    }
  }
  int ans = 0;
  int minn = ps[n];
  int maxx = ps[n];
  for (int i = n - 1; i; --i) {
    for (int d1 = 0; d1 < 2; ++d1) {
      for (int d2 = 0; d2 < 2; ++d2) {
        ans =
            max(ans, dp[i][k - 1][d1][d2] + (d1 ? ps[i] - minn : maxx - ps[i]));
      }
    }
    maxx = max(maxx, ps[i]);
    minn = min(minn, ps[i]);
  }
  cout << ans << "\n";
}
