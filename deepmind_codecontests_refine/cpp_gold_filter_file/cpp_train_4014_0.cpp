#include <bits/stdc++.h>
using namespace std;
int vis[410][410][2][2];
int _x, _y, n, d;
int dx[25], dy[25];
int dfs(int x, int y, int fip_p1, int fip_p2, int idx) {
  if (x * x + y * y > d * d) {
    return 1;
  }
  if (vis[x + 200][y + 200][fip_p1][fip_p2]) {
    return vis[x + 200][y + 200][fip_p1][fip_p2];
  }
  int i;
  for (i = 1; i <= n; ++i) {
    if (dfs(x + dx[i], y + dy[i], fip_p1, fip_p2, 3 - idx) == 2) {
      return vis[x + 200][y + 200][fip_p1][fip_p2] = 1;
    }
  }
  if (idx == 1 && fip_p1 == 0) {
    if (dfs(y, x, fip_p1 + 1, fip_p2, 3 - idx) == 1) {
      return vis[x + 200][y + 200][fip_p1][fip_p2] = 1;
    }
  }
  if (idx == 2 && fip_p2 == 0) {
    if (dfs(y, x, fip_p1, fip_p2 + 1, 3 - idx) == 1) {
      return vis[x + 200][y + 200][fip_p1][fip_p2] = 1;
    }
  }
  return vis[x + 200][y + 200][fip_p1][fip_p2] = 2;
}
int main() {
  int i;
  while (scanf("%d%d%d%d", &_x, &_y, &n, &d) != EOF) {
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= n; ++i) {
      scanf("%d%d", &dx[i], &dy[i]);
    }
    if (dfs(_x, _y, 0, 0, 1) == 1) {
      printf("Anton\n");
    } else {
      printf("Dasha\n");
    }
  }
}
