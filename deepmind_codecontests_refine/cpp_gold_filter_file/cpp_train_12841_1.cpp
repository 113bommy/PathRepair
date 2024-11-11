#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 305;
int n, dp[2 * N][N][N], a[N][N], sum;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      sum += a[i][j];
    }
  for (int j = 0; j < 2 * n; ++j)
    for (int i1 = 0; i1 < n; ++i1)
      for (int i2 = 0; i2 < n; ++i2) dp[j][i1][i2] = -INF;
  dp[0][0][0] = a[0][0];
  for (int d = 0; d < 2 * n; ++d)
    for (int i1 = 0; i1 < n; ++i1)
      for (int i2 = 0; i2 < n; ++i2) {
        int j1 = d - i1, j2 = d - i2, x = dp[d][i1][i2];
        if (i1 == i2 && j1 + 1 == j2 + 1)
          dp[d + 1][i1][i2] = max(dp[d + 1][i1][i2], x + a[i1][j1 + 1]);
        else
          dp[d + 1][i1][i2] =
              max(dp[d + 1][i1][i2], x + a[i1][j1 + 1] + a[i2][j2 + 1]);
        if (i1 == i2 + 1 && j1 + 1 == j2)
          dp[d + 1][i1][i2 + 1] = max(dp[d + 1][i1][i2 + 1], x + a[i1][j1 + 1]);
        else
          dp[d + 1][i1][i2 + 1] =
              max(dp[d + 1][i1][i2 + 1], x + a[i1][j1 + 1] + a[i2 + 1][j2]);
        if (i1 + 1 == i2 && j1 == j2 + 1)
          dp[d + 1][i1 + 1][i2] = max(dp[d + 1][i1 + 1][i2], x + a[i1 + 1][j1]);
        else
          dp[d + 1][i1 + 1][i2] =
              max(dp[d + 1][i1 + 1][i2], x + a[i1 + 1][j1] + a[i2][j2 + 1]);
        if (i1 + 1 == i2 + 1 && j1 == j2)
          dp[d + 1][i1 + 1][i2 + 1] =
              max(dp[d + 1][i1 + 1][i2 + 1], x + a[i1 + 1][j1]);
        else
          dp[d + 1][i1 + 1][i2 + 1] =
              max(dp[d + 1][i1 + 1][i2 + 1], x + a[i1 + 1][j1] + a[i2 + 1][j2]);
      }
  cout << dp[2 * n - 2][n - 1][n - 1];
  return 0;
}
