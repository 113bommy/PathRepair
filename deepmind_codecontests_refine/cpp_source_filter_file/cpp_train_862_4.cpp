#include <bits/stdc++.h>
using namespace std;
char sym[] = ".br";
long long int dp[800][800][3][3], ans = 0;
int mod = 1000000007;
int Right[800];
long long solve(int x, int y, int t1, int t2) {
  if (dp[x][y][t1][t2] != -1) return dp[x][y][t1][t2];
  if (y == Right[x]) {
    if (t1 == t2 || (t1 && t2)) return dp[x][y][t1][t2] = 0;
    if (y == x + 1) return dp[x][y][t1][t2] = 1;
  }
  dp[x][y][t1][t2] = 0;
  int c[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, i, j;
  if (Right[x] != y) {
    if (t1 == 0)
      c[0][0] = c[0][1] = c[0][2] = 0;
    else
      c[1][0] = c[1][1] = c[1][2] = c[2][0] = c[2][1] = c[2][2] = 0;
    c[1][1] = c[2][2] = 0;
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
        if (c[i][j])
          dp[x][y][t1][t2] +=
              (solve(x, Right[x], t1, i) * solve(1 + Right[x], y, j, t2)) % mod;
    dp[x][y][t1][t2] %= mod;
    return dp[x][y][t1][t2];
  } else {
    if (t1) c[t1][0] = c[t1][1] = c[t1][2] = 0;
    if (t2) c[0][t2] = c[1][t2] = c[2][t2] = 0;
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
        if (c[i][j]) dp[x][y][t1][t2] += solve(x + 1, y - 1, i, j);
    dp[x][y][t1][t2] %= mod;
    return dp[x][y][t1][t2];
  }
}
int main() {
  char str[800];
  stack<int> s;
  cin >> str;
  int n, i, j, k;
  n = strlen(str);
  for (i = n - 1; i >= 0; i--)
    if (str[i] == ')') {
      Right[i] = -1;
      s.push(i);
    } else {
      Right[i] = s.top();
      s.pop();
    }
  memset(dp, -1, sizeof dp);
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) ans += solve(0, n - 1, i, j);
  cout << ans;
}
