#include <bits/stdc++.h>
const int max_n = 101372;
struct edge {
  int v, num;
  edge *next;
  edge(int _v, int _num, edge *_next) : v(_v), num(_num), next(_next) {}
} * E[max_n];
int n, t = 0, size[max_n], prt[max_n], heavy[max_n], dep[max_n],
       edge_num[max_n], top[max_n], num[max_n], len[max_n], w[max_n],
       tree[max_n << 1];
inline int ls(int i) { return i << 1; }
inline int rs(int i) { return (i << 1) | 1; }
void get_size(int u) {
  size[u] = 1;
  heavy[u] = 0;
  dep[u] = prt[u] ? dep[prt[u]] + 1 : 0;
  for (edge *p = E[u]; p; p = p->next)
    if (p->v != prt[u]) {
      prt[p->v] = u;
      edge_num[p->v] = p->num;
      get_size(p->v);
      size[u] += size[p->v];
      if (size[heavy[u]] < size[p->v]) heavy[u] = p->v;
    }
}
void chain_cut(int u) {
  if (!top[u]) top[u] = u;
  num[u] = ++t;
  ++len[top[u]];
  if (heavy[u]) {
    top[heavy[u]] = top[u];
    chain_cut(heavy[u]);
  }
  for (edge *p = E[u]; p; p = p->next)
    if (p->v != prt[u] && p->v != heavy[u]) chain_cut(p->v);
}
inline void push_down(int i) {
  tree[ls(i)] += tree[i];
  tree[rs(i)] += tree[i];
  tree[i] = 0;
}
void add(int i, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    ++tree[i];
  } else {
    if (tree[i]) push_down(i);
    int mid = (l + r) >> 1;
    if (x <= mid) add(ls(i), l, mid, x, y);
    if (y > mid) add(rs(i), mid + 1, r, x, y);
  }
}
int query(int i, int l, int r, int pos) {
  if (l == r) return tree[i];
  if (tree[i]) push_down(i);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    return query(ls(i), l, mid, pos);
  else
    return query(rs(i), mid + 1, r, pos);
}
int main() {
  int m, u, v;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    E[u] = new edge(v, i, E[u]);
    E[v] = new edge(u, i, E[v]);
  }
  get_size(1);
  chain_cut(1);
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d", &u, &v);
    while (top[u] != top[v]) {
      if (dep[top[u]] > dep[top[v]]) {
        add(1, 1, n, num[top[u]], num[u]);
        u = prt[top[u]];
      } else {
        add(1, 1, n, num[top[v]], num[v]);
        v = prt[top[v]];
      }
    }
    if (u != v) {
      if (dep[u] > dep[v])
        add(1, 1, n, num[v] + 1, num[u]);
      else
        add(1, 1, n, num[u] + 1, num[v]);
    }
  }
  for (int i = 2; i <= n; ++i) w[edge_num[i]] = query(1, 1, n, num[i]);
  printf("%d", w[1]);
  for (int i = 2; i < n; ++i) printf(" %d", w[i]);
  putchar('\n');
  return 0;
}
