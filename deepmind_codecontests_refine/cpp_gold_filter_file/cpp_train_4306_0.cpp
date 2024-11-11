#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e14;
const double eps = 1e-10;
const double pi = acos(-1.0);
long long a[750][750];
long long dp[302][302][3];
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      a[i][j + i] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= 2; k++) {
        dp[i][j][k] = -inf;
      }
    }
  }
  dp[1][1][2 & 1] = a[1][2];
  for (int d = 2; d <= n + n - 1; d++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int x = 0; x < 2; x++) {
          for (int y = 0; y < 2; y++) {
            int tx = i + x;
            int ty = j + y;
            long long& res = dp[tx][ty][(d + 1) & 1];
            if (tx == ty) {
              res = max(res, dp[i][j][d & 1] + a[tx][d + 1]);
            } else {
              res = max(res, dp[i][j][d & 1] + a[tx][d + 1] + a[ty][d + 1]);
            }
          }
        }
        dp[i][j][d & 1] = -inf;
      }
    }
  }
  cout << dp[n][n][(n + n) & 1] << "\n";
  return 0;
}
