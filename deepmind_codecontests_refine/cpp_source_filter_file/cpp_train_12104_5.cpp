#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
int dp[MAXN][MAXN][MAXN][MAXN][2];
char s[MAXN][MAXN];
int n, m;
int dfs(int MINX, int MAXX, int MINY, int MAXY, int op) {
  int res = dp[MINX][MAXX][MINY][MAXY][op];
  if (res != -1) return res;
  bool vis[5];
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (((i + j) & 1) == op) {
        int x = i + j, y = i - j + m - 1;
        if (x >= MINX && x < MAXX && y >= MINY && y < MAXY) {
          int tmp = 0;
          if (s[i][j] == 'L') {
            tmp =
                dfs(MINX, x, MINY, MAXY, op) ^ dfs(x + 1, MAXX, MINY, MAXY, op);
          } else if (s[i][j] == 'R') {
            tmp =
                dfs(MINX, MAXX, MINY, y, op) ^ dfs(MINX, MAXX, y + 1, MAXY, op);
          } else if (s[i][j] == 'X') {
            tmp = dfs(MINX, x, MINY, y, op) ^ dfs(MINX, x, y + 1, MAXY, op) ^
                  dfs(x + 1, MAXX, MINY, y, op) ^
                  dfs(x + 1, MAXX, y + 1, MAXY, op);
          }
          vis[tmp] = true;
        }
      }
    }
  }
  while (vis[++res])
    ;
  return dp[MINX][MAXX][MINY][MAXY][op] = res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  memset(dp, -1, sizeof(dp));
  int t =
      dfs(0, n + m - 1, 0, n + m - 1, 0) ^ dfs(0, n + m - 1, 0, n + m - 1, 1);
  if (t)
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
