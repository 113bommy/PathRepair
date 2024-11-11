#include <bits/stdc++.h>
using namespace std;
const int N = 42;
long long dp[N][N][N][N], g[N][N], m, n, a[N][N], q, mn, a1, a2, a3, a4;
char w;
int main() {
  cin >> n >> m >> q;
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) {
      cin >> w;
      a[i][j] = (w == '1');
    }
  }
  for (long long x = 1; x < n + 1; x++) {
    for (long long y = 1; y < m + 1; y++)
      g[x][y] = (g[x - 1][y] + (a[x][y] == 0)) * (a[x][y] == 0);
  }
  for (long long x = 1; x < n + 1; x++) {
    for (long long y = 1; y < m + 1; y++) {
      for (long long i = 1; i < x + 1; i++) {
        for (long long j = 1; j < y + 1; j++) {
          dp[i][j][x][y] =
              dp[i][j][x][y - 1] + dp[i][j][x - 1][y] - dp[i][j][x - 1][y - 1];
          mn = x - i + 1;
          for (long long p = y; p >= j; p--) {
            mn = min(mn, g[x][p]);
            ;
            dp[i][j][x][y] += mn;
          }
        }
      }
    }
  }
  for (long long i = 0; i < m; i++) {
    cin >> a1 >> a2 >> a3 >> a4;
    cout << dp[a1][a2][a3][a4] << endl;
  }
}
