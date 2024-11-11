#include <bits/stdc++.h>
using namespace std;
int n, dp[55][55][55][55];
char G[55][55];
int DFS(int x1, int y1, int x2, int y2) {
  if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
  if (x1 == x2 && y1 == y2) {
    if (G[x1][y1] == '#')
      dp[x1][y1][x2][y2] = 1;
    else
      dp[x1][y1][x2][y2] = 0;
    return dp[x1][y1][x2][y2];
  }
  dp[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
  for (int i = x1; i < x2; ++i)
    dp[x1][y1][x2][y2] =
        min(DFS(x1, y1, i, y2) + DFS(i + 1, y1, x2, y2), dp[x1][y1][x2][y2]);
  for (int i = y1; i < y2; ++i)
    dp[x1][y1][x2][y2] =
        min(DFS(x1, i + 1, x2, y2) + DFS(x1, y1, x2, i), dp[x1][y1][x2][y2]);
  return dp[x1][y1][x2][y2];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> G[i][j];
  memset(dp, -1, sizeof(dp));
  printf("%d", DFS(1, 1, n, n));
  return 0;
}
