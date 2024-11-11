#include <bits/stdc++.h>
using namespace std;
const int N = 160;
int dp[2][N][N * N], a[N];
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  memset(dp, 0x3f, sizeof dp);
  int n, k, s;
  cin >> n >> k >> s;
  for (int i = (1); i < (n + 1); ++i) cin >> a[i];
  dp[0][0][0] = dp[1][0][0] = 0;
  for (int i = (1); i < (n + 1); ++i) {
    for (int j = (1); j < (i + 1); ++j)
      for (int k = (i - j); k < (n * n + 1); ++k)
        dp[1][j][k] = min(dp[1][j][k], dp[0][j - 1][k - (i - j)] + a[i]);
    memcpy(dp[0], dp[1], sizeof dp[1]);
  }
  int ans = n * n;
  for (int i = (0); i < (min(s, n * n) + 1); ++i) ans = min(ans, dp[0][k][i]);
  cout << ans << "\n";
  return 0;
}
