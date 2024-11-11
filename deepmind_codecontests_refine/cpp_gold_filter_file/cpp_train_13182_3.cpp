#include <bits/stdc++.h>
int n, root, p[100010], val[100010];
struct edge {
  int to;
  edge *next;
} e[200010], *et = e, *last[100010];
void add(int u, int v) {
  *++et = (edge){v, last[u]}, last[u] = et;
  *++et = (edge){u, last[v]}, last[v] = et;
}
int dfn[100010], ck, dep[100010], end[100010];
void dfs(int u, int fa) {
  dfn[u] = ++ck;
  dep[u] = dep[fa] + 1;
  for (edge *it = last[u]; it; it = it->next)
    if (fa != it->to) {
      dfs(it->to, u);
    }
  end[u] = ck;
}
bool comp(const int &i, const int &j) {
  return dep[i] < dep[j] || (dep[i] == dep[j] && dfn[i] < dfn[j]);
}
struct node {
  int min;
  node *ls, *rs;
} t[5000010], *tt = t, *rt[100010];
void build(node *&rt, int l, int r) {
  rt = ++tt;
  if (l == r) {
    rt->min = 1e9;
    return;
  }
  int mid = l + r >> 1;
  build(rt->ls, l, mid);
  build(rt->rs, mid + 1, r);
  rt->min = std::min(rt->ls->min, rt->rs->min);
}
void modify(node *la, node *&rt, int l, int r, int pos, int x) {
  rt = ++tt;
  *rt = *la;
  if (r < pos || pos < l) return;
  if (l == r) {
    rt->min = x;
    return;
  }
  int mid = l + r >> 1;
  modify(la->ls, rt->ls, l, mid, pos, x);
  modify(la->rs, rt->rs, mid + 1, r, pos, x);
  rt->min = std::min(rt->ls->min, rt->rs->min);
}
int query(node *rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) return rt->min;
  if (r < L || R < l) return 1e9;
  int mid = l + r >> 1;
  return std::min(query(rt->ls, l, mid, L, R), query(rt->rs, mid + 1, r, L, R));
}
int fin[100010];
int main() {
  scanf("%d%d", &n, &root);
  for (int i = 1; i <= n; i++) scanf("%d", val + i), p[i] = i;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  dfs(root, 0);
  std::sort(p + 1, p + n + 1, comp);
  int m;
  build(rt[0], 1, n);
  int maxd = 0;
  for (int i = 1; i <= n; i++) {
    fin[dep[p[i]]] = i;
    maxd = dep[p[i]];
    modify(rt[i - 1], rt[i], 1, n, dfn[p[i]], val[p[i]]);
  }
  scanf("%d", &m);
  int ans = 0;
  while (m--) {
    int x, k;
    scanf("%d%d", &x, &k);
    x = (x + ans) % n + 1;
    k = (k + ans) % n;
    int d = std::min(k + dep[x], maxd);
    ans = query(rt[fin[d]], 1, n, dfn[x], end[x]);
    printf("%d\n", ans);
  }
  return 0;
}
