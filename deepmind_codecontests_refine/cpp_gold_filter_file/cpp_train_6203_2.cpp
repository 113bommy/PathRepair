#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const char al[5] = {"DLRU"};
const int maxn = 1005;
int n, m, k, sx, sy, d[maxn][maxn], id, x, y;
char G[maxn][maxn], res[maxn * maxn];
queue<pair<int, int> > que;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%s", G[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (G[i][j] == 'X') sx = i, sy = j;
  memset(d, 0x3f, sizeof d);
  que.push(pair<int, int>(sx, sy));
  d[sx][sy] = 0;
  while (!que.empty()) {
    x = que.front().first, y = que.front().second;
    que.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || d[nx][ny] < inf ||
          G[nx][ny] == '*')
        continue;
      que.push(pair<int, int>(nx, ny));
      d[nx][ny] = d[x][y] + 1;
    }
  }
  x = sx, y = sy;
  while (id < k) {
    int i = 0;
    for (; i < 4; ++i) {
      int tx = x + dx[i], ty = y + dy[i];
      if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
      if (d[tx][ty] <= k - id - 1) {
        x = tx, y = ty, res[id++] = al[i];
        break;
      }
    }
    if (i == 4) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  puts(res);
  return 0;
}
