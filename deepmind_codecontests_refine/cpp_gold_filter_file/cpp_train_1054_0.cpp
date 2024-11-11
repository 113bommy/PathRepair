#include <bits/stdc++.h>
using namespace std;
struct nod {
  int l, r;
  long long lazy, mi;
} t[500002 * 4];
struct edg {
  int end, next, s;
} g[500002 * 2];
int n, q, b, l[500002], r[500002], w;
int fa[500002], tot, ed[500002];
long long d[500002], ans[500002];
vector<int> G[500002];
void add(int a, int b, int c) {
  g[++tot] = (edg){b, fa[a], c};
  fa[a] = tot;
}
void up(int w) { t[w].mi = min(t[w << 1].mi, t[w << 1 | 1].mi); }
void push_down(int w) {
  t[w << 1].lazy += t[w].lazy;
  t[w << 1 | 1].lazy += t[w].lazy;
  t[w << 1].mi += t[w].lazy;
  t[w << 1 | 1].mi += t[w].lazy;
  t[w].lazy = 0;
}
void build(int w, int l, int r) {
  t[w] = (nod){l, r, 0, 0};
  if (l == r) {
    t[w].mi = d[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(w << 1, l, mid);
  build(w << 1 | 1, mid + 1, r);
  up(w);
  return;
}
void change(int w, int l, int r, long long s) {
  if (t[w].l == l && t[w].r == r) {
    t[w].lazy += s;
    t[w].mi += s;
    return;
  }
  if (t[w].lazy != 0) push_down(w);
  int mid = (t[w].l + t[w].r) >> 1;
  if (r <= mid)
    change(w << 1, l, r, s);
  else if (l > mid)
    change(w << 1 | 1, l, r, s);
  else {
    change(w << 1, l, mid, s);
    change(w << 1 | 1, mid + 1, r, s);
  }
  up(w);
}
void update(int w, long long s) {
  change(1, 1, n, s);
  change(1, w, ed[w], -2ll * s);
}
long long query(int w, int l, int r) {
  if (t[w].l == l && t[w].r == r) {
    return t[w].mi;
  }
  if (t[w].lazy != 0) push_down(w);
  int mid = (t[w].l + t[w].r) >> 1;
  if (r <= mid)
    return query(w << 1, l, r);
  else if (l > mid)
    return query(w << 1 | 1, l, r);
  else {
    return min(query(w << 1, l, mid), query(w << 1 | 1, mid + 1, r));
  }
  up(w);
}
void dfs(int w) {
  for (int i = 0; i < G[w].size(); i++) {
    int u = G[w][i];
    ans[u] = query(1, l[u], r[u]);
  }
  for (int i = fa[w]; i; i = g[i].next) {
    int u = g[i].end;
    update(u, g[i].s);
    dfs(u);
    update(u, -g[i].s);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &b, &w);
    add(b, i + 1, w);
    d[i + 1] = d[b] + w;
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &b, &l[i], &r[i]);
    G[b].push_back(i);
  }
  for (int i = n; i; i--)
    if (!fa[i])
      ed[i] = i;
    else
      ed[i] = max(ed[i], ed[g[fa[i]].end]), d[i] = 1e18;
  build(1, 1, n);
  dfs(1);
  for (int i = 1; i <= q; i++) printf("%I64d\n", ans[i]);
  return 0;
}
