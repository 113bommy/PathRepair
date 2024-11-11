#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 100005;
const int maxm = 500005;
const int inf = 0x3f3f3f3f;
int n;
char a[55][55];
int dp[51][51][51][51];
int dfs(int x1, int y1, int x2, int y2) {
  if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
  if (x1 == x2 && y1 == y2) return (a[x1][x2] == '#');
  dp[x1][y1][x2][y2] = max(y2 - y1 + 1, x2 - x1 + 1);
  for (int i = x1; i < x2; i++) {
    dp[x1][y1][x2][y2] =
        min(dp[x1][y1][x2][y2], dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
  }
  for (int j = y1; j < y2; j++) {
    dp[x1][y1][x2][y2] =
        min(dp[x1][y1][x2][y2], dfs(x1, y1, x2, j) + dfs(x1, j + 1, x2, y2));
  }
  return dp[x1][y1][x2][y2];
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  cout << dfs(1, 1, n, n) << '\n';
  return 0;
}
