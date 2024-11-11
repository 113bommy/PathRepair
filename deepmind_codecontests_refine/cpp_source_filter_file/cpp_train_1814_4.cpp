#include <bits/stdc++.h>
inline int in() {
  int k = 0;
  char ch = getchar();
  bool p = 1;
  while (ch < '-') ch = getchar();
  if (ch == '-') ch = getchar(), p = 0;
  while (ch > '-') k = k * 10 + ch - '0', ch = getchar();
  return p ? k : -k;
}
const int inf = 2e9;
int dp[25][25][1 << 8], ans, X[15], Y[15], n, m, d, val[15], v[1 << 8];
char mp[25][25];
inline int calc(int x, int y, int tx, int s) {
  for (int i = 0; i < d; ++i)
    if (y > Y[i] && (x >= X[i]) + (tx >= X[i]) == 1) s ^= 1 << i;
  return s;
}
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
struct node {
  int x, y, s;
  node(int x = 0, int y = 0, int s = 0) : x(x), y(y), s(s) {}
};
void bfs(int sx, int sy) {
  memset(dp, 0, sizeof dp);
  dp[sx][sy][0] = 1;
  std::queue<node> Q;
  Q.push(node(sx, sy, 0));
  while (!Q.empty()) {
    node now = Q.front();
    Q.pop();
    int x = now.x, y = now.y, s = now.s;
    for (int i = 0; i < 4; ++i) {
      int tx = x + dx[i], ty = y + dy[i];
      if (tx < 1 || ty < 1 || tx > n || ty > m || mp[tx][ty] != '.') continue;
      int ts = calc(x, y, tx, s);
      if (!dp[tx][ty][ts])
        dp[tx][ty][ts] = dp[x][y][s] + 1, Q.push(node(tx, ty, ts));
    }
  }
  for (int i = 0; i < (1 << d); ++i)
    if (dp[sx][sy][i]) ans = std::max(ans, v[i] - dp[sx][sy][i] + 1);
}
int main() {
  n = in(), m = in();
  int fz = 0, sx, sy;
  for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (mp[i][j] >= '1' && mp[i][j] <= '9')
        d = std::max(d, mp[i][j] - '0');
      else if (mp[i][j] == 'B')
        ++fz;
      else if (mp[i][j] == 'S')
        sx = i, sy = j, mp[i][j] = '.';
  if (!d && !fz) return puts("0"), 0;
  for (int i = 0; i < d; ++i) val[i] = in();
  for (int i = 0; i < fz; ++i) val[i + d] = -inf;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (mp[i][j] >= '1' && mp[i][j] <= '9')
        X[mp[i][j] - '1'] = i, Y[mp[i][j] - '1'] = j;
      else if (mp[i][j] == 'B')
        X[d] = i, Y[d++] = j;
  for (int i = 0; i < (1 << d); ++i)
    for (int j = 0; j < d; ++j)
      if (i >> j & 1) v[i] += val[j];
  bfs(sx, sy);
  printf("%d\n", ans);
  return 0;
}
