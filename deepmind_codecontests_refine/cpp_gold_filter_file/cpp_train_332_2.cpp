#include <bits/stdc++.h>
using namespace std;
vector<int> G[200005];
int n;
int f[200005], size[200005], son[200005], top[200005], d[200005];
void dfs1(int u, int pre, int deep) {
  f[u] = pre;
  d[u] = deep;
  size[u] = 1;
  for (auto v : G[u]) {
    if (v == pre) continue;
    dfs1(v, u, deep + 1);
    size[u] += size[v];
    if (size[son[u]] < size[v]) son[u] = v;
  }
}
void dfs2(int u, int tp) {
  top[u] = tp;
  if (son[u]) dfs2(son[u], tp);
  for (auto v : G[u]) {
    if (v == son[u] || v == f[u]) continue;
    dfs2(v, v);
  }
}
int LCA(int u, int v) {
  while (top[u] != top[v]) {
    if (d[top[u]] < d[top[v]]) swap(u, v);
    u = f[top[u]];
  }
  if (d[u] > d[v]) swap(u, v);
  return u;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(1, 0, 0);
  dfs2(1, 1);
  int q;
  cin >> q;
  while (q--) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    int lca1 = LCA(a, b);
    int dis1 = d[a] + d[b] - 2 * d[lca1];
    if (k >= dis1 && (k - dis1) % 2 == 0) {
      puts("YES");
      continue;
    }
    int lca2 = LCA(a, x), lca3 = LCA(b, y);
    int lca4 = LCA(a, y), lca5 = LCA(b, x);
    int dis2 = d[a] + d[x] - 2 * d[lca2];
    dis2 += d[b] + d[y] - 2 * d[lca3] + 1;
    int dis3 = d[a] + d[y] - 2 * d[lca4];
    dis3 += d[b] + d[x] - 2 * d[lca5] + 1;
    if (k >= dis2 && (k - dis2) % 2 == 0) {
      puts("YES");
      continue;
    }
    if (k >= dis3 && (k - dis3) % 2 == 0) {
      puts("YES");
      continue;
    }
    puts("NO");
  }
}
