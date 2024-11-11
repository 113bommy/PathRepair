#include <bits/stdc++.h>
using namespace std;
stack<int> S;
const long long mod = 1e9 + 7;
char s[705];
int pos[705];
long long dp[705][705][3][3], ans;
void solve(int l, int r) {
  if (l == r) return;
  if (l + 1 == r) {
    dp[l][r][0][1] = 1;
    dp[l][r][1][0] = 1;
    dp[l][r][0][2] = 1;
    dp[l][r][2][0] = 1;
    return;
  }
  if (pos[l] == r) {
    solve(l + 1, r - 1);
    for (int i = 0; i <= 2; ++i)
      for (int j = 0; j <= 2; ++j) {
        if (i != 1) dp[l][r][1][0] += dp[l + 1][r - 1][i][j];
        if (j != 1) dp[l][r][0][1] += dp[l + 1][r - 1][i][j];
        if (j != 2) dp[l][r][0][2] += dp[l + 1][r - 1][i][j];
        if (i != 2) dp[l][r][2][0] += dp[l + 1][r - 1][i][j];
        for (int x = 0; x <= 2; ++x)
          for (int y = 0; y < 2; ++y) dp[l][r][x][y] %= mod;
      }
  } else if (pos[l] != r) {
    solve(l, pos[l]);
    solve(pos[l] + 1, r);
    int tmp = pos[l];
    for (int i = 0; i <= 2; ++i)
      for (int j = 0; j <= 2; ++j)
        for (int x = 0; x <= 2; ++x)
          for (int y = 0; y <= 2; ++y) {
            if ((x == 1 && y == 1) || (x == y && y == 2)) continue;
            dp[l][r][i][j] += (dp[l][tmp][i][x] * dp[tmp + 1][r][y][j]) % mod;
            dp[l][r][i][j] %= mod;
          }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; ++i) {
    if (s[i] == '(')
      S.push(i);
    else
      pos[S.top()] = i, S.pop();
  }
  solve(1, len);
  int n = len;
  for (int i = 0; i <= 2; ++i)
    for (int j = 0; j <= 2; ++j) ans += dp[1][n][i][j], ans %= mod;
  printf("%lld", ans);
  return 0;
}
