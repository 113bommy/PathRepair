#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010, inf = 1 << 30;
int N, M, father[maxn], nxt[maxn], toit[maxn], len[maxn], side[maxn], id[maxn],
    seq[maxn], D[maxn], cnt;
int DFN, dfn[maxn], top[maxn], size[maxn], con[maxn], ans[maxn],
    tree[maxn << 2], cover[maxn << 2];
bool exist[maxn];
inline int find(int a) {
  if (father[a] != a) father[a] = find(father[a]);
  return father[a];
}
inline void add(int a, int b, int c, int d) {
  nxt[++cnt] = side[a];
  side[a] = cnt;
  toit[cnt] = b;
  len[cnt] = c;
  id[cnt] = d;
}
inline void ins(int a, int b, int c, int d) {
  add(a, b, c, d);
  add(b, a, c, d);
}
inline int gi() {
  char ch;
  int ret = 0, f = 1;
  do ch = getchar();
  while (!(ch >= '0' && ch <= '9') && ch != '-');
  if (ch == '-') f = -1, ch = getchar();
  do ret = ret * 10 + ch - '0', ch = getchar();
  while (ch >= '0' && ch <= '9');
  return ret * f;
}
struct Edge {
  int u, v, c, id;
  inline void read(int i) {
    id = i;
    u = gi(), v = gi(), c = gi();
  }
  inline void bind() {
    int a = find(u), b = find(v);
    if (a != b) {
      father[a] = b;
      exist[id] = true;
      ins(a, b, c, id);
    }
  }
  friend inline bool operator<(const Edge &a, const Edge &b) {
    return a.c < b.c;
  }
} edge[maxn];
inline void Div(int now, int Top) {
  dfn[now] = ++DFN;
  seq[DFN] = now;
  top[now] = Top;
  int heavy = 0;
  for (int i = side[now]; i; i = nxt[i])
    if (toit[i] != father[now] && size[toit[i]] > size[heavy]) heavy = toit[i];
  if (!heavy) return;
  Div(heavy, Top);
  for (int i = side[now]; i; i = nxt[i])
    if (toit[i] != father[now] && toit[i] != heavy) Div(toit[i], toit[i]);
}
inline void dfs(int now) {
  size[now] = 1;
  for (int i = side[now]; i; i = nxt[i])
    if (toit[i] != father[now]) {
      father[toit[i]] = now, con[toit[i]] = i;
      D[toit[i]] = D[now] + 1, dfs(toit[i]);
      size[now] += size[toit[i]];
    }
}
inline void mst() {
  sort(edge + 1, edge + M + 1);
  cnt = 1;
  for (int i = 1; i <= N; ++i) father[i] = i;
  for (int i = 1; i <= M; ++i) edge[i].bind();
  father[1] = 0;
  dfs(1);
  Div(1, 1);
}
inline int ask(int now, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return tree[now];
  int mid = (l + r) >> 1;
  if (qr <= mid)
    return ask(now << 1, l, mid, ql, qr);
  else if (ql > mid)
    return ask(now << 1 | 1, mid + 1, r, ql, qr);
  else
    return max(ask(now << 1, l, mid, ql, mid),
               ask(now << 1 | 1, mid + 1, r, mid + 1, qr));
}
inline void modify(int now, int l, int r, int ql, int qr, int c) {
  if (l == ql && r == qr) {
    cover[now] = min(cover[now], c);
    return;
  }
  int mid = (l + r) >> 1;
  if (qr <= mid)
    modify(now << 1, l, mid, ql, qr, c);
  else if (ql > mid)
    modify(now << 1 | 1, mid + 1, r, ql, qr, c);
  else {
    modify(now << 1, l, mid, ql, mid, c);
    modify(now << 1 | 1, mid + 1, r, mid + 1, qr, c);
  }
}
inline int Query(int a, int b, int c) {
  int ret = -inf;
  while (top[a] != top[b]) {
    if (D[top[a]] < D[top[b]]) swap(a, b);
    ret = max(ret, ask(1, 1, N, dfn[top[a]], dfn[a]));
    modify(1, 1, N, dfn[top[a]], dfn[a], c);
    a = father[top[a]];
  }
  if (D[a] < D[b]) swap(a, b);
  if (a != b) {
    ret = max(ret, ask(1, 1, N, dfn[b] + 1, dfn[a]));
    modify(1, 1, N, dfn[b] + 1, dfn[a], c);
  }
  return ret;
}
inline void build(int now, int l, int r) {
  cover[now] = inf;
  if (l == r) {
    tree[now] = len[con[seq[l]]];
    return;
  }
  int mid = (l + r) >> 1;
  build(now << 1, l, mid);
  build(now << 1 | 1, mid + 1, r);
  tree[now] = max(tree[now << 1], tree[now << 1 | 1]);
}
inline int query(int now, int l, int r, int pos) {
  if (l == r) return cover[now];
  int mid = (l + r) >> 1;
  if (pos <= mid)
    return min(cover[now], query(now << 1, l, mid, pos));
  else
    return min(cover[now], query(now << 1 | 1, mid + 1, r, pos));
}
inline void work() {
  build(1, 1, N);
  for (int i = 1; i <= M; ++i)
    if (!exist[edge[i].id])
      ans[edge[i].id] = Query(edge[i].u, edge[i].v, edge[i].c);
  for (int i = 2; i <= N; ++i) ans[id[con[i]]] = query(1, 1, N, dfn[i]);
  for (int i = 1; i <= M; ++i) {
    if (ans[i] == inf)
      ans[i] = -1;
    else
      --ans[i];
    printf("%d ", ans[i]);
  }
}
int main() {
  N = gi();
  M = gi();
  for (int i = 1; i <= M; ++i) edge[i].read(i), ans[i] = inf;
  mst();
  work();
  return 0;
}
