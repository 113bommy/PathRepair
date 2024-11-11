#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, sx, sy, ex, ey;
char g[N][N];
char rot[128];
bool vis[4][N][N];
const char U[] = "+|^LRD";
const char D[] = "+|vLRU";
const char L[] = "+-<URD";
const char R[] = "+->ULD";
char rotate(char c, int k) {
  while (k-- > 0) c = rot[c];
  return c;
}
bool has(char c, const char arr[]) {
  for (int k = 0; k < 6; ++k)
    if (arr[k] == c) return true;
  return false;
}
int bfs() {
  --sx, --sy, --ex, --ey;
  queue<int> qx, qy, qd, qw;
  if (!vis[0][sx][sy]) {
    qx.push(sx);
    qy.push(sy);
    qd.push(0);
    qw.push(0);
    vis[0][sx][sy] = true;
  };
  while (!qx.empty()) {
    int x = qx.front(), y = qy.front(), d = qd.front(), w = qw.front();
    qx.pop();
    qy.pop();
    qd.pop();
    qw.pop();
    ;
    if (x == ex && y == ey) return w;
    char c = rotate(g[x][y], d);
    int nd = (d + 1) % 4;
    if (!vis[nd][x][y]) {
      qx.push(x);
      qy.push(y);
      qd.push(nd);
      qw.push(w + 1);
      vis[nd][x][y] = true;
    };
    if (x > 0 && has(c, U) && has(rotate(g[x - 1][y], d), D))
      if (!vis[d][x - 1][y]) {
        qx.push(x - 1);
        qy.push(y);
        qd.push(d);
        qw.push(w + 1);
        vis[d][x - 1][y] = true;
      };
    if (x + 1 < n && has(c, D) && has(rotate(g[x + 1][y], d), U))
      if (!vis[d][x + 1][y]) {
        qx.push(x + 1);
        qy.push(y);
        qd.push(d);
        qw.push(w + 1);
        vis[d][x + 1][y] = true;
      };
    if (y > 0 && has(c, L) && has(rotate(g[x][y - 1], d), R))
      if (!vis[d][x][y - 1]) {
        qx.push(x);
        qy.push(y - 1);
        qd.push(d);
        qw.push(w + 1);
        vis[d][x][y - 1] = true;
      };
    if (y + 1 < m && has(c, R) && has(rotate(g[x][y + 1], d), L))
      if (!vis[d][x][y + 1]) {
        qx.push(x);
        qy.push(y + 1);
        qd.push(d);
        qw.push(w + 1);
        vis[d][x][y + 1] = true;
      };
  }
  return -1;
}
int main() {
  rot['+'] = '+';
  rot['-'] = '|';
  rot['|'] = '-';
  rot['^'] = '>';
  rot['>'] = 'v';
  rot['v'] = '<';
  rot['<'] = '^';
  rot['L'] = 'U';
  rot['U'] = 'R';
  rot['R'] = 'D';
  rot['D'] = 'L';
  rot['*'] = '*';
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", g[i]);
  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
  printf("%d\n", bfs());
}
