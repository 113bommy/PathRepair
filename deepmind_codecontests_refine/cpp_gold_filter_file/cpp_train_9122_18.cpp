#include <bits/stdc++.h>
using namespace std;
int dp[110][110][30];
char G[110][110];
int n, m;
int dfs(int x, int y, int c) {
  if (dp[x][y][c]) return dp[x][y][c];
  for (int i = 1; i <= n; i++) {
    if (G[x][i] - 'a' >= c && (dfs(y, i, G[x][i] - 'a') == 2))
      return dp[x][y][G[x][i] - 'a'] = 1;
  }
  return dp[x][y][c] = 2;
}
int main() {
  while (~scanf("%d %d", &n, &m)) {
    memset(G, 0, sizeof(G));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
      int x, y;
      char c;
      scanf("%d %d %c", &x, &y, &c);
      G[x][y] = c;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dfs(i, j, 0) == 1)
          printf("A");
        else
          printf("B");
      }
      printf("\n");
    }
  }
  return 0;
}
