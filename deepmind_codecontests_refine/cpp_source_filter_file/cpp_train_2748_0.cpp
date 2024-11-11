#include <bits/stdc++.h>
using namespace std;
bool vis[1024][2];
int main() {
  int n, m, i, j, cnt, x, y;
  while (~scanf("%d %d", &n, &m)) {
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < m; ++i) {
      scanf("%d %d", &x, &y);
      vis[x - 1][0] = true;
      vis[y - 1][1] = true;
    }
    for (cnt = 0, i = 1; i < n - 1; ++i) {
      if (!vis[i][0]) ++cnt;
      if (!vis[i][1]) ++cnt;
    }
    if ((n & 1) && !vis[n / 2 + 1][0] && !vis[n / 2 + 1][1]) --cnt;
    printf("%d\n", cnt);
  }
  return 0;
}
