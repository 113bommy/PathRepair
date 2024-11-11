#include <bits/stdc++.h>
using namespace std;
int n, k, dfn[200011], rk[200011], dep[200011], siz[200011], fa[200011], clk;
long long ans = -1e18;
bool vis[200011];
struct edge {
  int v, next;
  edge() {}
  edge(int _v, int _next) {
    v = _v;
    next = _next;
  }
} e[400011];
int head[200011], sz;
void init() {
  memset(head, -1, sizeof(head));
  sz = 0;
}
void insert(int u, int v) {
  e[++sz] = edge(v, head[u]);
  head[u] = sz;
}
struct node {
  int l, r, mx, id, tag;
  node() {
    mx = -1e9;
    id = 0;
    tag = 0;
  }
} tree[800011];
node merge(node a, node b) {
  node c;
  c.l = a.l;
  c.r = b.r;
  c.mx = max(a.mx, b.mx);
  if (c.mx == a.mx)
    c.id = a.id;
  else
    c.id = b.id;
  return c;
}
void pushup(int x) { tree[x] = merge(tree[(x << 1)], tree[(x << 1 | 1)]); }
void apply(int x, int p) {
  tree[x].tag += p;
  tree[x].mx += p;
}
void pushdown(int x) {
  if (tree[x].tag)
    apply((x << 1), tree[x].tag), apply((x << 1 | 1), tree[x].tag),
        tree[x].tag = 0;
}
void build(int l, int r, int x) {
  tree[x].l = l;
  tree[x].r = r;
  if (l == r) {
    tree[x].mx = dep[l];
    tree[x].id = l;
    return;
  }
  build(l, l + r >> 1, (x << 1));
  build((l + r >> 1) + 1, r, (x << 1 | 1));
  pushup(x);
}
void add(int l, int r, int p, int x) {
  if (l <= tree[x].l && tree[x].r <= r) {
    apply(x, p);
    return;
  }
  pushdown(x);
  if (l <= tree[x].l + tree[x].r >> 1) add(l, r, p, (x << 1));
  if (r > tree[x].l + tree[x].r >> 1) add(l, r, p, (x << 1 | 1));
  pushup(x);
}
void dfs(int u, int f) {
  siz[u] = 1;
  dfn[u] = ++clk;
  rk[clk] = u;
  fa[u] = f;
  dep[u] = dep[f] + 1;
  for (int i = head[u]; ~i; i = e[i].next)
    if (e[i].v ^ f) dfs(e[i].v, u), siz[u] += siz[e[i].v];
}
int main() {
  scanf("%d%d", &n, &k);
  init();
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    insert(u, v);
    insert(v, u);
  }
  dfs(1, 0);
  ans = max(ans, -1ll * (n / 2) * (n - n / 2));
  int cnt = n;
  build(1, n, 1);
  for (int i = 1; i <= k; ++i) {
    int x = rk[tree[1].id];
    while (x && !vis[x])
      vis[x] = 1, add(dfn[x], dfn[x] + siz[x] - 1, -1, 1), --cnt, x = fa[x];
    ans = max(
        ans, 1ll * i * (n - i) - 1ll * min(n / 2, cnt) * (n - min(n / 2, cnt)));
  }
  printf("%lld\n", ans);
  return 0;
}
