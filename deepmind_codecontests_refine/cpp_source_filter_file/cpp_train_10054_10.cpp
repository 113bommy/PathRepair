#include <bits/stdc++.h>
using namespace std;
long n, i, j, a[4][100001], dp[4][100001];
int main() {
  cin >> n;
  for (i = 0; i < 3; i++)
    for (j = 0; j < n; j++) cin >> a[i][j];
  dp[2][n - 1] = a[2][n - 1];
  dp[1][n - 1] = dp[2][n - 1] + a[1][n - 1];
  dp[0][n - 1] = dp[1][n - 1] + a[0][n - 1];
  for (i = n - 2; i >= 0; i--) {
    dp[0][i] = a[0][i] + max(max(max(dp[0][i + 1], a[1][i] + dp[1][i + 1]),
                                 a[1][i] + a[2][i] + dp[2][i + 1]),
                             a[0][i + 1] + a[1][i + 1] + a[1][i] + a[2][i] +
                                 a[2][i + 1] + dp[2][i + 2]);
    dp[1][i] = a[1][i] + max(max(dp[1][i + 1], a[0][i] + dp[0][i + 1]),
                             a[2][i] + dp[2][i + 1]);
    dp[2][i] = a[2][i] + max(max(max(dp[2][i + 1], a[1][i] + dp[1][i + 1]),
                                 a[1][i] + a[0][i] + dp[0][i + 1]),
                             a[2][i + 1] + a[1][i + 1] + a[1][i] + a[0][i] +
                                 a[0][i + 1] + dp[0][i + 2]);
  }
  cout << dp[0][0];
}
