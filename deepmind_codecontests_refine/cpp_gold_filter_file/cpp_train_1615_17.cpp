#include <bits/stdc++.h>
using namespace std;
const int N = 234567;
int m;
int cnt;
int f[N];
vector<int> g[N];
vector<int> gg[N];
void dfs(int x, int pa = -1) {
  for (int y : g[x]) {
    if (y != pa) {
      dfs(y, x);
      f[x] += f[y];
      if (f[y] > 0 && f[y] < m) {
        ++cnt;
        gg[x].push_back(y);
        gg[y].push_back(x);
      }
    }
  }
}
int n;
int q[N];
int d[N];
int bfs(int from) {
  memset(d, -1, sizeof d);
  q[0] = from;
  d[from] = 0;
  for (int qh = 0, qt = 1; qh < qt; ++qh) {
    int x = q[qh];
    for (int y : gg[x]) {
      if (d[y] == -1) {
        d[y] = d[x] + 1;
        q[qt++] = y;
      }
    }
  }
  int u = -1;
  for (int i = 0; i < n; ++i) {
    if (u == -1 || d[i] > d[u]) {
      u = i;
    }
  }
  return u;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    gg[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  memset(f, 0, sizeof f);
  int v = -1;
  for (int i = 0; i < m; ++i) {
    int pos;
    scanf("%d", &pos);
    --pos;
    f[pos] = 1;
    v = pos;
  }
  cnt = 0;
  dfs(0);
  int u = bfs(v);
  v = bfs(u);
  printf("%d\n", min(u, v) + 1);
  printf("%d\n", 2 * cnt - d[v]);
  return 0;
}
