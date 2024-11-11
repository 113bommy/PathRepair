#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int a[n][m];
  for (long long int i = (0); i < (n); i++)
    for (long long int j = (0); j < (m); j++) cin >> a[i][j];
  int dp[n][(m / 2) + 1][k + 1];
  memset(dp, -1, sizeof dp);
  for (long long int i = (0); i < (n); i++) {
    if (i == 0)
      dp[i][0][0] = 0;
    else {
      for (long long int x = (0); x < (k); x++)
        dp[i][0][x] = dp[i - 1][m / 2][x];
    }
    for (long long int j = (0); j < (m); j++) {
      for (long long int x = (m / 2 - 1); x >= (0); x--) {
        for (long long int y = (0); y < (k); y++) {
          if (dp[i][x][y] != -1) {
            dp[i][x + 1][y] = max(dp[i][x][y], dp[i][x + 1][y]);
            dp[i][x + 1][(y + a[i][j]) % k] =
                max(dp[i][x + 1][(y + a[i][j]) % k], dp[i][x][y] + a[i][j]);
          }
        }
      }
    }
  }
  cout << dp[n - 1][0][0] << "\n";
}
