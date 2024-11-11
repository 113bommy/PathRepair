#include <bits/stdc++.h>
using namespace std;
long long dp[55][55];
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  dp[0][0] = 1;
  for (int i = 1; i <= 31; ++i)
    for (int j = 1; j <= 31; ++j) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
  long long sol = 0;
  for (int i = 4; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (i + j == t) {
        sol = sol + dp[n + 1][i + 1] * dp[m + 1][j + 1];
      }
  cout << sol << '\n';
  return 0;
}
