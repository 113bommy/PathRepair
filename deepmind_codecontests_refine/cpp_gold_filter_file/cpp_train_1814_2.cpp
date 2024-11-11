#include <bits/stdc++.h>
using namespace std;
const int N = 45, K = 1 << 10, inf = 1e6 + 5;
struct point {
  int x, y, S;
  point() {}
  point(int xx, int yy, int SS) { x = xx, y = yy, S = SS; }
};
char c[N][N];
int dx[10] = {0, 0, -1, 0, 1}, dy[10] = {0, 1, 0, -1, 0};
int n, m, sx, sy, cnt, ans, gx[N * N], gy[N * N], val[N * N], sum[K],
    dp[N][N][K];
bool in(int tx, int ty, int x, int y, int k) {
  return tx == gx[k] && ty < gy[k] && x < tx ||
         x == gx[k] && y < gy[k] && x > tx;
}
int bfs() {
  queue<point> q;
  q.push(point(sx, sy, 0));
  while (!q.empty()) {
    point k = q.front();
    q.pop();
    if (k.x == sx && k.y == sy) ans = max(ans, sum[k.S] - dp[k.x][k.y][k.S]);
    for (int i = 1; i <= 4; i++) {
      int tx = k.x + dx[i], ty = k.y + dy[i], tS = k.S;
      if (tx < 1 || tx > n || ty < 1 || ty > m || c[tx][ty] != '.') continue;
      for (int j = 1; j <= cnt; j++)
        tS ^= in(tx, ty, k.x, k.y, j) * (1 << (j - 1));
      if (!dp[tx][ty][tS] && !(tx == sx && ty == sy && tS == 0))
        q.push(point(tx, ty, tS)), dp[tx][ty][tS] = dp[k.x][k.y][k.S] + 1;
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", c[i] + 1);
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == 'S') sx = i, sy = j, c[i][j] = '.';
      if ('0' <= c[i][j] && c[i][j] <= '9')
        ++cnt, gx[c[i][j] - '0'] = i, gy[c[i][j] - '0'] = j;
    }
  }
  for (int i = 1; i <= cnt; i++) scanf("%d", &val[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (c[i][j] == 'B') ++cnt, gx[cnt] = i, gy[cnt] = j, val[cnt] = -inf;
  for (int i = 1; i < (1 << cnt); i++)
    for (int j = 1; j <= cnt; j++)
      if ((1 << (j - 1)) & i) sum[i] += val[j];
  printf("%d\n", bfs());
  return 0;
}
