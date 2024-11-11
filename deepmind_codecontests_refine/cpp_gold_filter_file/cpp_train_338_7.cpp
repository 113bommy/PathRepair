#include <bits/stdc++.h>
template <typename Tp>
void read(Tp &res) {
  static char ch;
  ch = getchar(), res = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
}
const int MAXN = 5e5 + 19;
int n, q;
struct Edge {
  int to, next, id;
} edge[MAXN << 1];
int head[MAXN], cnt;
inline void add(int from, int to, int id) {
  edge[++cnt].to = to;
  edge[cnt].next = head[from];
  edge[cnt].id = id;
  head[from] = cnt;
}
int su, rt, dep[MAXN], type[MAXN];
void dfs1(int node, int f) {
  dep[node] = dep[f] + 1;
  if (dep[node] > dep[rt]) rt = node;
  for (int i = head[node]; i; i = edge[i].next)
    if (edge[i].to != f) dfs1(edge[i].to, node);
}
int to[MAXN], dfn[MAXN], size[MAXN], id[MAXN], ind;
bool c[MAXN];
void dfs2(int node, int f) {
  dep[node] = dep[f] + 1, size[node] = 1, id[dfn[node] = ++ind] = node;
  for (int i = head[node]; i; i = edge[i].next)
    if (edge[i].to != f)
      to[edge[i].id] = edge[i].to, c[edge[i].to] = c[node] ^ type[edge[i].id],
      dfs2(edge[i].to, node), size[node] += size[edge[i].to];
}
struct Node {
  int max[2];
  bool tag;
} tr[MAXN << 2];
inline void push_up(int node) {
  for (int i = 0; i < 2; ++i)
    tr[node].max[i] = std::max(tr[(node << 1)].max[i ^ tr[node].tag],
                               tr[(node << 1 | 1)].max[i ^ tr[node].tag]);
}
void build(int node, int L, int R) {
  if (L == R) {
    tr[node].max[c[id[L]]] = dep[id[L]];
    tr[node].max[c[id[L]] ^ 1] = 0;
    return;
  }
  int mid = (L + R) >> 1;
  build((node << 1), L, mid), build((node << 1 | 1), mid + 1, R);
  tr[node].tag = 0, push_up(node);
}
void modify(int node, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    std::swap(tr[node].max[0], tr[node].max[1]);
    tr[node].tag ^= 1;
    return;
  }
  int mid = (L + R) >> 1;
  if (l <= mid) modify((node << 1), L, mid, l, r);
  if (r > mid) modify((node << 1 | 1), mid + 1, R, l, r);
  push_up(node);
}
int ans[MAXN], Q[MAXN];
void solve(int root) {
  ind = 0, dfs2(root, 0);
  build(1, 1, n);
  for (int i = 1; i <= q; ++i)
    modify(1, 1, n, dfn[to[Q[i]]], dfn[to[Q[i]]] + size[to[Q[i]]] - 1),
        ans[i] = std::max(ans[i], tr[1].max[c[root]]);
}
int main() {
  read(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v), read(type[i]);
    add(u, v, i), add(v, u, i);
  }
  dfs1(1, 0), dfs1(su = rt, 0);
  read(q);
  for (int i = 1; i <= q; ++i) read(Q[i]);
  solve(su), solve(rt);
  for (int i = 1; i <= q; ++i) printf("%d\n", ans[i] - 1);
  return 0;
}
