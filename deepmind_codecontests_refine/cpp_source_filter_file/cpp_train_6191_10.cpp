#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
bool cur1;
int n, m, q;
struct Graph {
  int tot, head[maxn], to[maxn << 1], nxt[maxn << 1];
  void add_edge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
  }
  void add_edges(int x, int y) {
    add_edge(x, y);
    add_edge(y, x);
  }
} G, E;
int id, dfn[maxn], low[maxn];
int block;
bool instk[maxn];
int top2, stk[maxn];
vector<int> BCC[maxn], belong[maxn];
bool cut[maxn];
void tarjan(int f, int x) {
  belong[x].clear();
  dfn[x] = low[x] = ++id;
  instk[x] = 1;
  stk[++top2] = x;
  for (int i = G.head[x]; i; i = G.nxt[i]) {
    int y = G.to[i];
    if (!dfn[y]) {
      tarjan(x, y);
      low[x] = min(low[x], low[y]);
      if (low[y] >= dfn[x]) {
        if (f)
          cut[x] = 1;
        else
          f = -1;
        block++;
        BCC[block].clear();
        stk[++top2] = x;
        for (int z = -1; z != y;) {
          z = stk[top2--];
          BCC[block].push_back(z);
          belong[z].push_back(block);
        }
      }
    } else if (y != f)
      low[x] = min(low[x], dfn[y]);
  }
}
int into[maxn];
int A[maxn];
int dep[maxn], fa[maxn], top[maxn];
int sz[maxn], son[maxn];
int L[maxn];
void dfs1(int f, int x) {
  dep[x] = dep[f] + 1;
  fa[x] = f;
  sz[x] = 1;
  for (int i = E.head[x]; i; i = E.nxt[i]) {
    int y = E.to[i];
    if (y == f) continue;
    dfs1(x, y);
    sz[x] += sz[y];
    if (sz[son[x]] < sz[y]) son[x] = y;
  }
}
void dfs2(int Top, int x) {
  dfn[++id] = x;
  L[x] = id;
  top[x] = Top;
  if (son[x]) dfs2(Top, son[x]);
  for (int i = E.head[x]; i; i = E.nxt[i]) {
    int y = E.to[i];
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
struct Node {
  int val, x;
  bool operator<(const Node &_) const { return val > _.val; }
};
priority_queue<Node> T[maxn];
struct SegTree {
  struct node {
    int l, r, mn;
  } tree[maxn << 2];
  int solve(int x) {
    x = dfn[x];
    while (!T[x].empty()) {
      if (A[T[x].top().x] != T[x].top().val)
        T[x].pop();
      else
        break;
    }
    return T[x].empty() ? (int)2e9 : T[x].top().val;
  }
  void up(int p) { tree[p].mn = min(tree[p << 1].mn, tree[p << 1 | 1].mn); }
  void build(int l, int r, int p) {
    tree[p] = (node){l, r, (int)2e9};
    if (l == r) return (void)(tree[p].mn = solve(l));
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    up(p);
  }
  void update(int x, int p) {
    if (tree[p].l == tree[p].r) return (void)(tree[p].mn = solve(x));
    int mid = tree[p].l + tree[p].r >> 1;
    update(x, p << 1 | (x > mid));
    up(p);
  }
  int Query(int l, int r, int p) {
    if (tree[p].l == l && tree[p].r == r) return tree[p].mn;
    int mid = tree[p].l + tree[p].r >> 1;
    if (r <= mid)
      return Query(l, r, p << 1);
    else if (l > mid)
      return Query(l, r, p << 1 | 1);
    else
      return min(Query(l, mid, p << 1), Query(mid + 1, r, p << 1 | 1));
  }
} S;
int solve(int x, int y) {
  int res = (int)2e9;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    res = min(res, S.Query(L[top[x]], L[x], 1));
    x = fa[top[x]];
  }
  if (dep[x] < dep[y]) swap(x, y);
  if (fa[y]) res = min(res, S.Query(L[fa[y]], L[fa[y]], 1));
  return min(res, S.Query(L[y], L[x], 1));
}
bool cur2;
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    G.add_edges(x, y);
  }
  block = n;
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(0, i);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < belong[i].size(); j++) {
      E.add_edges(i, belong[i][j]);
    }
  }
  memset(dfn, 0, sizeof(dfn));
  id = 0;
  for (int i = 1; i <= block; i++) {
    if (!dep[i]) {
      dfs1(0, i);
      dfs2(i, i);
    }
  }
  for (int i = 1; i <= n; i++) {
    T[i].push((Node){A[i], i});
    T[fa[i]].push((Node){A[i], i});
  }
  S.build(1, block, 1);
  for (int i = 1, x, y; i <= q; i++) {
    char c;
    scanf("%s%d%d", &c, &x, &y);
    if (c == 'A') {
      if (x == y)
        printf("%d\n", A[x]);
      else
        printf("%d\n", solve(x, y));
    } else {
      A[x] = y;
      T[x].push((Node){A[x], x});
      T[fa[x]].push((Node){A[x], x});
      S.update(L[x], 1);
      if (fa[x]) S.update(L[fa[x]], 1);
    }
  }
  return 0;
}
