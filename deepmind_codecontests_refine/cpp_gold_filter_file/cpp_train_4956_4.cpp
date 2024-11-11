#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int maxk = 2e4 + 10;
const int inf = 0x3f3f3f3f;
int n, m, k;
bool g[maxn][maxn];
struct Block {
  int l, r, b, t;
};
Block b[maxk];
int bnum;
bool vis[maxk];
int d[maxk];
int res;
int start, stop;
void bfs() {
  memset(d, 0, sizeof d);
  res = inf;
  queue<int> q;
  q.push(start);
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = true;
    if (u == stop) {
      res = min(d[u], res);
      continue;
    } else if (b[u].b >= n - 1 || b[u].r >= m - 1) {
      res = min(d[u] + 1, res);
      continue;
    }
    for (int i = 0; i < bnum; i++) {
      if (vis[i]) continue;
      if (b[u].t > b[i].b + 2 && (b[u].l > b[i].r + 2 || b[u].r < b[i].l - 2))
        continue;
      if (b[u].b < b[i].t - 2 && (b[u].l > b[i].r + 2 || b[u].r < b[i].l - 2))
        continue;
      vis[i] = true;
      d[i] = d[u] + 1;
      q.push(i);
    }
  }
}
bool dvis[maxn][maxn];
void dfs(int r, int c, int bnum) {
  if (dvis[r][c]) return;
  if (r == 1 && c == 1) start = bnum;
  if (r == n && c == m) stop = bnum;
  dvis[r][c] = 1;
  b[bnum].l = min(b[bnum].l, c);
  b[bnum].r = max(b[bnum].r, c);
  b[bnum].b = max(b[bnum].b, r);
  b[bnum].t = min(b[bnum].t, r);
  if (r > 1 && g[r - 1][c]) dfs(r - 1, c, bnum);
  if (r < n && g[r + 1][c]) dfs(r + 1, c, bnum);
  if (c > 1 && g[r][c - 1]) dfs(r, c - 1, bnum);
  if (c < m && g[r][c + 1]) dfs(r, c + 1, bnum);
}
int main() {
  memset(g, 0, sizeof g);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int r, c;
    scanf("%d%d", &r, &c);
    g[r][c] = 1;
  }
  bnum = 0;
  start = stop = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] && !dvis[i][j]) {
        b[bnum].r = b[bnum].l = j;
        b[bnum].b = b[bnum].t = i;
        dfs(i, j, bnum);
        bnum++;
      }
    }
  }
  bfs();
  if (res < inf)
    printf("%d\n", res);
  else
    printf("-1\n");
}
