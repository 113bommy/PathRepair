#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char g[maxn][maxn];
bool v[maxn][maxn];
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int m, n;
bool ok;
bool dfs(int x, int y, int px, int py, int cnt) {
  v[x][y] = 1;
  for (int k = 0; k < 4; ++k) {
    int dx = x + dir[k][0];
    int dy = y + dir[k][1];
    if (0 <= dx && dx < n && 0 <= dy && dy < m && g[dx][dy] == g[x][y]) {
      if (!v[dx][dy])
        dfs(dx, dy, x, y, cnt + 1);
      else if ((dx != px || dy != py) && cnt >= 3)
        ok = 1;
    }
  }
  return ok;
}
int main() {
  while (~scanf("%d %d", &n, &m)) {
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; ++i) {
      scanf("%s", g[i]);
    }
    ok = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!v[i][j]) {
          if (dfs(i, j, -1, -1, 0)) {
            puts("Yes");
            return 0;
          }
        }
      }
    }
    puts("No");
  }
}
