#include <bits/stdc++.h>
using namespace std;
int v[501], dp[501][501];
int main() {
  int n, i, j, k, len;
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> v[i];
  for (len = 1; len <= n; ++len)
    for (i = 1; i <= n - len + 1; ++i) {
      j = i + len - 1;
      if (i == j)
        dp[i][j] = 1;
      else if (j == i + 1) {
        if (v[i] == v[j])
          dp[i][j] = 1;
        else
          dp[i][j] = 2;
      } else {
        dp[i][j] = dp[i + 1][j] + 1;
        if (v[i] == v[i + 1]) dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
        for (k = i + 2; k <= j; ++k)
          if (v[i] == v[k])
            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
      }
    }
  cout << dp[1][n];
  return 0;
}
