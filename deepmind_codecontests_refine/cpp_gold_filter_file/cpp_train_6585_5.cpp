#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct EDGE {
  int to, nxt;
  EDGE() {}
  EDGE(int a, int b) {
    to = a;
    nxt = b;
  }
} edge[N * 2];
int d[N], t[N], fa[N * 2][21], len[N * 2], tt[N * 2], c[N];
int tot;
void addedge(int x, int y) {
  edge[++tot] = EDGE(y, tt[x]);
  tt[x] = tot;
}
int lca(int x, int y) {
  if (len[x] > len[y]) swap(x, y);
  for (int i = 20; i >= 0; i--)
    if (len[y] - len[x] >= (1 << i)) y = fa[y][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  return fa[x][0];
}
void dfs(int x) {
  for (int p = tt[x]; p > 0; p = edge[p].nxt) {
    int y = edge[p].to;
    len[y] = len[x] + 1;
    dfs(y);
  }
}
int main() {
  int n, m, cnt, a, b;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= m; i++) t[i] = i;
  cnt = m;
  for (int i = 2; i <= m; i++) {
    scanf("%d%d", &a, &b);
    cnt++;
    fa[t[a]][0] = cnt;
    fa[t[b]][0] = cnt;
    addedge(cnt, t[a]);
    addedge(cnt, t[b]);
    t[a] = cnt;
  }
  dfs(cnt);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= cnt; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
  for (int i = 1; i < n; i++) {
    int x = lca(d[i], d[i + 1]);
    if (x > m)
      x -= m;
    else
      x = 0;
    c[x]++;
  }
  for (int i = m - 1; i >= 0; i--) c[i] += c[i + 1];
  for (int i = 1; i <= m; i++) printf("%d\n", c[i]);
  return 0;
}
