#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 6 * N;
int n, m;
int h[N], e[M], ne[M], w[N], idx;
int top[N], id[N], sz[N], cnt;
int dep[N], son[N], fat[N], mp[N], nw[N];
int fa[N][17];
int dist[N];
struct Edge {
  int a, b, w;
} edge[N];
struct Node {
  int l, r;
  int sum;
} tr[N << 2];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void bfs(int root) {
  memset(dist, 0x3f, sizeof dist);
  queue<int> q;
  q.push(root);
  dist[root] = 1;
  dist[0] = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + 1) {
        q.push(j);
        dist[j] = dist[t] + 1;
        fa[j][0] = t;
        for (int k = 1; k <= 15; k++) fa[j][k] = fa[fa[j][k - 1]][k - 1];
      }
    }
  }
}
int lca(int a, int b) {
  if (dist[a] < dist[b]) swap(a, b);
  for (int k = 16; k >= 0; k--) {
    if (dist[fa[a][k]] >= dist[b]) {
      a = fa[a][k];
    }
  }
  if (a == b) return a;
  for (int k = 16; k >= 0; k--) {
    if (fa[a][k] != fa[b][k]) {
      a = fa[a][k];
      b = fa[b][k];
    }
  }
  return fa[a][0];
}
void dfs1(int u, int father, int depth) {
  sz[u] = 1, fat[u] = father, dep[u] = depth;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (j == father) continue;
    dfs1(j, u, depth + 1);
    sz[u] += sz[j];
    if (sz[son[u]] < sz[j]) son[u] = j;
  }
}
void dfs2(int u, int father, int t) {
  id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], u, t);
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (j == father || j == son[u]) continue;
    dfs2(j, u, j);
  }
}
void pushup(int u) { tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; }
void build(int u, int l, int r) {
  tr[u].l = l, tr[u].r = r;
  if (l == r) {
    tr[u].sum = nw[l];
    return;
  }
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
void modify(int u, int x, int k) {
  if (tr[u].l == x && tr[u].r == x) {
    tr[u].sum = k;
    return;
  }
  int mid = tr[u].l + tr[u].r >> 1;
  if (x <= mid)
    modify(u << 1, x, k);
  else
    modify(u << 1 | 1, x, k);
  pushup(u);
}
int query(int u, int l, int r) {
  if (tr[u].l >= l && tr[u].r <= r) {
    return tr[u].sum;
  }
  int mid = tr[u].l + tr[u].r >> 1;
  int res = 0;
  if (l <= mid) res += query(u << 1, l, r);
  if (r > mid) res += query(u << 1 | 1, l, r);
  return res;
}
int query_path(int u, int v) {
  int res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res += query(1, id[top[u]], id[u]);
    u = fat[top[u]];
  }
  if (u != v) {
    if (dep[u] < dep[v]) swap(u, v);
    res += query(1, id[v] + 1, id[u]);
  }
  return res;
}
int main(void) {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
    edge[i] = {a, b, 1};
  }
  bfs(1);
  dfs1(1, -1, 1);
  for (int i = 1; i <= n - 1; i++) {
    int a = edge[i].a, b = edge[i].b, ww = edge[i].w;
    if (dep[a] < dep[b]) swap(a, b);
    mp[i] = a;
    w[a] = ww;
  }
  dfs2(1, -1, 1);
  build(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    int op, u, v;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &u);
      int dot = mp[u];
      modify(1, id[dot], 1);
    } else if (op == 2) {
      scanf("%d", &u);
      int dot = mp[u];
      modify(1, id[dot], 0);
    } else {
      scanf("%d%d", &u, &v);
      int p = lca(u, v);
      int d = dist[u] + dist[v] - 2 * dist[p];
      int qu = query_path(u, v);
      if (qu != d)
        printf("-1\n");
      else
        printf("%d\n", d);
    }
  }
  return 0;
}
