#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 3e3 + 5;
long long mod = 1e9 + 7;
char mp[maxn][maxn];
long long dp[maxn][maxn];
long long slove(int x, int y, int tx, int ty) {
  if (mp[x][y] == '#') return 0;
  memset(dp, 0, sizeof(dp));
  dp[x][y] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] == '#') continue;
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
      dp[i][j] %= mod;
    }
  return dp[tx][ty];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  long long ans = (slove(1, 2, n - 1, m) * slove(2, 1, n, m - 1) % mod -
                   slove(1, 2, n, m - 1) * slove(2, 1, n - 1, m) % mod + mod) %
                  mod;
  cout << ans << endl;
  return 0;
}
