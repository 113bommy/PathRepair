#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long grid[3][N], dp[N][4];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < 3; i++) {
    for (long long j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }
  fill(&dp[0][0], &dp[n][3], -1e18);
  dp[0][0] = 0;
  auto sum = [&](long long j, long long l, long long r) {
    long long res = 0;
    if (l > r) swap(l, r);
    for (long long i = l; i <= r; i++) {
      res += grid[i][j];
    }
    return res;
  };
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < 3; j++) {
      for (long long k = 0; k < 3; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum(i, j, k));
      }
    }
    dp[i][0] = max(dp[i][0], dp[i - 1][3] + sum(i, 0, 2));
    dp[i][2] = max(dp[i][2], dp[i - 1][3] + sum(i, 0, 2));
    dp[i][3] = max(dp[i][3], max(dp[i - 1][0], dp[i - 1][2]) + sum(i, 0, 2));
  }
  cout << dp[n][2] << "\n";
}
