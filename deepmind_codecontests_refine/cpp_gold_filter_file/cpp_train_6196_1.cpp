#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int c[505], n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i < 505; ++i) {
    for (int j = 1; j < 505; ++j) {
      dp[i][j] = INT_MAX;
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (c[i] == c[i + 1])
      dp[i][i + 1] = 1;
    else
      dp[i][i + 1] = 2;
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = 1; j + i - 1 <= n; ++j) {
      dp[j][j + i - 1] = min(dp[j][j + i - 1], 1 + dp[j + 1][j + i - 1]);
      if (c[j] == c[j + i - 1])
        dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j + 1][j + i - 2]);
      if (c[j] == c[j + 1])
        dp[j][j + i - 1] = min(dp[j][j + i - 1], 1 + dp[j + 2][j + i - 1]);
      for (int k = j + 2; k < j + i - 1; ++k) {
        if (c[j] == c[k])
          dp[j][j + i - 1] =
              min(dp[j][j + i - 1], dp[j + 1][k - 1] + dp[k + 1][j + i - 1]);
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}
