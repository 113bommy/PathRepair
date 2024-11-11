#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
const int N = 3005;
const int MOD = 1e9 + 7;
long long dp[2][N][N];
char mp[N][N];
void go_dp(int x, int y, int z) {
  dp[z][x][y] = mp[x][y] != '#';
  for (int i = (int)(y + 1); i <= (int)(m); ++i)
    dp[z][1][i] = dp[z][1][i - 1] && mp[1][i] != '#';
  for (int i = (int)(x + 1); i <= (int)(n); ++i)
    dp[z][i][1] = dp[z][i - 1][1] && mp[i][1] != '#';
  for (int i = (int)(2); i <= (int)(n); ++i)
    for (int j = (int)(2); j <= (int)(m); ++j) {
      if (mp[i][j] == '#')
        dp[z][i][j] = 0;
      else {
        dp[z][i][j] = dp[z][i - 1][j] + dp[z][i][j - 1];
        if (dp[z][i][j] >= MOD) dp[z][i][j] -= MOD;
      }
    }
}
int main() {
  int t, x, y, z, ca = 1;
  scanf("%d%d", &(n), &(m));
  for (int i = (int)(1); i <= (int)(n); ++i) scanf("%s", (mp[i] + 1));
  go_dp(1, 2, 0), go_dp(2, 1, 1);
  long long ans = 0;
  ans = dp[0][n][m - 1] * dp[1][n - 1][m] % MOD -
        dp[0][n - 1][m] * dp[1][n][m - 1] % MOD;
  if (ans < 0) ans += MOD;
  cout << MOD - ans << endl;
  return 0;
}
