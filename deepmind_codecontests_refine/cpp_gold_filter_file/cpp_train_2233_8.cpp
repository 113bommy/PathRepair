#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Edge {
  int to, nex;
} edge[N << 1];
int idx;
int h[N];
void add_edge(int u, int v) {
  edge[++idx] = {v, h[u]};
  h[u] = idx;
}
int ans[N << 2], cnt;
int vis[N];
int a[N];
int n, m;
void dfs(int p, int fa) {
  vis[p] = 1;
  for (int i = h[p]; ~i; i = edge[i].nex) {
    int to = edge[i].to;
    if (!vis[to]) {
      a[to] ^= 1;
      ans[++cnt] = to;
      dfs(to, p);
      a[p] ^= 1;
      ans[++cnt] = p;
    }
  }
  if (a[p]) {
    a[fa] ^= 1;
    ans[++cnt] = fa;
    a[p] ^= 1;
    ans[++cnt] = p;
  }
}
int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int root = 1;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      root = i;
      break;
    }
  a[root] ^= 1;
  ans[++cnt] = root;
  dfs(root, 0);
  for (int i = 1; i <= n; i++)
    if (!vis[i] && a[i]) {
      printf("-1\n");
      return 0;
    }
  if (cnt >= 3 && !ans[cnt - 1]) cnt -= 3;
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  return 0;
}
