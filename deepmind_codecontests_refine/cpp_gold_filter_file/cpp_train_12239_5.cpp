#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
struct Segment_Tree {
  int dep, f, tag;
} t[200005 << 2];
struct Qry {
  int x, tm, id;
} q[200005];
struct _Edge {
  int to, next;
} Edge[200005 << 1];
int head[200005], CNT;
int top[200005], dfn[200005], rec[200005], dep[200005], son[200005], sz[200005],
    ans[200005], fa[200005], n, m, tot;
inline void AddEdge(int u, int v) {
  Edge[++CNT] = (_Edge){v, head[u]};
  head[u] = CNT;
  return;
}
void dfs1(int u, int deep) {
  dep[u] = deep;
  son[u] = 0;
  sz[u] = 1;
  for (int e = head[u]; e; e = Edge[e].next) {
    int v = Edge[e].to;
    dfs1(v, deep + 1);
    sz[u] += sz[v];
    if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
  }
  return;
}
void dfs2(int u, int upp) {
  top[u] = upp;
  dfn[u] = ++tot;
  rec[tot] = u;
  if (son[u])
    dfs2(son[u], upp);
  else
    return;
  for (int e = head[u]; e; e = Edge[e].next)
    if (Edge[e].to != son[u]) dfs2(Edge[e].to, Edge[e].to);
  return;
}
void Build(int o, int l, int r) {
  t[o].f = t[o].tag = -2147483640;
  if (l == r) {
    t[o].dep = 2 * dep[rec[l]];
    return;
  }
  int mid = (l + r) >> 1;
  Build(o << 1, l, mid);
  Build(o << 1 | 1, mid + 1, r);
  t[o].dep = max(t[o << 1].dep, t[o << 1 | 1].dep);
}
inline void up(int o, int v) {
  t[o].f = max(t[o].f, v + t[o].dep);
  t[o].tag = max(t[o].tag, v);
}
inline void PushDown(int o) {
  if (t[o].tag == -2147483640) return;
  up(o << 1, t[o].tag);
  up(o << 1 | 1, t[o].tag);
  t[o].tag = -2147483640;
  return;
}
void Update(int o, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) {
    up(o, v);
    return;
  }
  int mid = (l + r) >> 1;
  PushDown(o);
  if (ql <= mid) Update(o << 1, l, mid, ql, qr, v);
  if (mid < qr) Update(o << 1 | 1, mid + 1, r, ql, qr, v);
  t[o].f = max(t[o << 1].f, t[o << 1 | 1].f);
}
int Query(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[o].f;
  int mid = (l + r) >> 1, ret = -2147483640;
  PushDown(o);
  if (ql <= mid) ret = max(ret, Query(o << 1, l, mid, ql, qr));
  if (mid < qr) ret = max(ret, Query(o << 1 | 1, mid + 1, r, ql, qr));
  return ret;
}
inline int Calc(int x, int tm) {
  int vl = dep[x] + tm, u = x, ret = 0, Ans;
  while (u) {
    if (Query(1, 1, n, dfn[top[u]], dfn[u]) <= vl) {
      u = fa[top[u]];
    } else {
      int l = dfn[top[u]] + 1, r = dfn[u] + 1;
      if (Query(1, 1, n, dfn[u], dfn[u]) > vl)
        ret = u;
      else {
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (Query(1, 1, n, mid, dfn[u]) <= vl)
            ret = mid, r = mid - 1;
          else
            l = mid + 1;
        }
        ret = fa[rec[ret]];
      }
      break;
    }
  }
  if (!ret) ret = 1;
  u = x;
  Ans = 2 * (dep[x] - dep[ret]) + tm;
  while (top[u] ^ top[ret]) {
    Update(1, 1, n, dfn[top[u]], dfn[u], Ans - dep[x]);
    u = fa[top[u]];
  }
  Update(1, 1, n, dfn[ret], dfn[u], Ans - dep[x]);
  return Ans;
}
inline bool cmp1(Qry A, Qry B) {
  return ((dep[A.x] + A.tm) ^ (dep[B.x] + B.tm))
             ? dep[A.x] + A.tm < dep[B.x] + B.tm
             : A.x < B.x;
}
int main() {
  n = gi() + 1;
  m = gi();
  for (int i = 2; i <= n; i++) fa[i] = gi() + 1, AddEdge(fa[i], i);
  dfs1(1, 1);
  dfs2(1, 1);
  Build(1, 1, n);
  for (int i = 1; i <= m; i++) q[i].x = gi() + 1, q[i].tm = gi(), q[i].id = i;
  sort(q + 1, q + m + 1, cmp1);
  for (int i = 1; i <= m; i++) ans[q[i].id] = Calc(q[i].x, q[i].tm);
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
