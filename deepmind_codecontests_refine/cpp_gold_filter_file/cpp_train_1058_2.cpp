#include <bits/stdc++.h>
using namespace std;
char G[51][51];
int n;
int dp[51][51][51][51];
int dfs(int x1, int y1, int x2, int y2) {
  if (dp[x1][y1][x2][y2] >= 0) return dp[x1][y1][x2][y2];
  if (x1 == x2 && y1 == y2) return dp[x1][y1][x2][y2] = (G[x1][y1] == '#');
  int ans = 1e9;
  for (int i = x1; i < x2; i++)
    ans = min(ans, dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
  for (int i = y1; i < y2; i++)
    ans = min(ans, dfs(x1, y1, x2, i) + dfs(x1, i + 1, x2, y2));
  ans = min(ans, max(x2 - x1 + 1, y2 - y1 + 1));
  dp[x1][y1][x2][y2] = ans;
  return ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", G[i] + 1);
  printf("%d", dfs(1, 1, n, n));
  return 0;
}
