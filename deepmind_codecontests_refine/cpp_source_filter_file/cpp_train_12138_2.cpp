#include <bits/stdc++.h>
using namespace std;
char g[1005][1005];
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[1005][1005][4];
bool ok;
int n, m;
void dfs(int x, int y, int dir, int t) {
  if (t > 2) return;
  if (vis[x][y][dir]) return;
  vis[x][y][dir] = 1;
  if (g[x][y] == 'T') {
    ok = 1;
    return;
  }
  for (int i = 0; i < 4; i++) {
    int xx = x + d[i][0];
    int yy = y + d[i][1];
    if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
    if (g[xx][yy] == '*') continue;
    dfs(xx, yy, i, t + (i != dir));
    if (ok) return;
  }
}
int main() {
  ok = 0;
  scanf("%d %d", &n, &m);
  int sx, sy;
  for (int i = 1; i <= n; i++) {
    scanf("%s", g[i] + 1);
    for (int j = 1; j <= m; j++)
      if (g[i][j] == 'S') {
        sx = i;
        sy = j;
      }
  }
  for (int i = 0; i < 4; i++) {
    dfs(sx, sy, i, 0);
    if (ok) break;
  }
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
