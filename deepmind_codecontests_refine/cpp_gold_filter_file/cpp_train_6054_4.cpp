#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long dp[2001][1001][2];
long long n, ans = 0;
long long dfs(long long x, long long y, long long z) {
  if (x >= 2 * n) return 0;
  if (dp[x][y][z] != -1) return dp[x][y][z];
  if (z == 1) {
    long long kk = 0;
    if (y - 1 >= 0) kk = dfs(x + 1, y - 1, 0);
    if ((y + 1) <= (2 * n - x)) kk = (kk + dfs(x + 1, y + 1, 0)) % 1000000007;
    return dp[x][y][z] = kk;
  } else {
    long long kk = 0, ff = 0;
    if (y - 1 >= 0) {
      kk = (1 + dfs(x + 1, y - 1, 1)) % 1000000007;
      ff = dfs(x + 1, y - 1, 0);
    }
    if ((y + 1) <= (2 * n - x)) {
      kk = (kk + dfs(x + 1, y + 1, 0)) % 1000000007;
      ff = (ff + 1 + dfs(x + 1, y + 1, 1)) % 1000000007;
    }
    return dp[x][y][z] = max(kk, ff);
  }
}
int32_t main() {
  fastio();
  cin >> n;
  for (long long i = 0; i < 2001; i++)
    for (long long j = 0; j < 1001; j++)
      for (long long k = 0; k < 2; k++) dp[i][j][k] = -1;
  ans = max(dfs(0, 0, 1), dfs(0, 0, 0));
  cout << ans;
}
