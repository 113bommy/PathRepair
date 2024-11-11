#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
struct Segment_Tree {
  int dep, f, tag;
} t[800005 << 2];
struct Qry {
  int x, tm, id;
} q[800005];
struct _Edge {
  int to, next;
} Edge[800005 << 1];
int head[800005], CNT;
int top[800005], dfn[800005], rec[800005], dep[800005], son[800005], sz[800005],
    ans[800005], fa[800005], n, m, tot;
inline void AddEdge(int a, int b) {
  Edge[++CNT].to = b, Edge[CNT].next = head[a], head[a] = CNT;
}
void dfs(int x, int tp) {
  top[x] = tp;
  dfn[x] = ++rec[0], rec[rec[0]] = x;
  if (son[x]) dfs(son[x], tp);
  for (int i = head[x]; i; i = Edge[i].next)
    if (Edge[i].to != son[x]) dfs(Edge[i].to, Edge[i].to);
}
void Build(int x, int l, int r) {
  t[x].f = t[x].tag = -2147483640;
  if (l == r) {
    t[x].dep = (dep[rec[l]] << 1);
    return;
  }
  int mid = (l + r) >> 1;
  Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r);
  t[x].dep = max(t[x << 1].dep, t[x << 1 | 1].dep);
}
inline void up(int x, int y) {
  t[x].f = max(t[x].f, t[x].dep + y), t[x].tag = max(t[x].tag, y);
}
inline void PushDown(int x) {
  if (t[x].tag != -2147483640)
    up(x << 1, t[x].tag), up(x << 1 | 1, t[x].tag), t[x].tag = -2147483640;
}
void Update(int x, int l, int r, int a, int b, int c) {
  if (a <= l && r <= b) {
    up(x, c);
    return;
  }
  PushDown(x);
  int mid = (l + r) >> 1;
  if (a <= mid) Update(x << 1, l, mid, a, b, c);
  if (b > mid) Update(x << 1 | 1, mid + 1, r, a, b, c);
  t[x].f = max(t[x << 1].f, t[x << 1 | 1].f);
}
int Query(int x, int l, int r, int a, int b) {
  if (a <= l && r <= b) return t[x].f;
  PushDown(x);
  int mid = (l + r) >> 1;
  if (b <= mid) return Query(x << 1, l, mid, a, b);
  if (a > mid) return Query(x << 1 | 1, mid + 1, r, a, b);
  return max(Query(x << 1, l, mid, a, b), Query(x << 1 | 1, mid + 1, r, a, b));
}
inline int Calc(int x, int tm) {
  int vl = dep[x] + tm, u = x, ret = 0, Ans;
  ret = x;
  while (ret) {
    if (Query(1, 1, n, dfn[top[ret]], dfn[ret]) <= vl) {
      ret = fa[top[ret]];
      continue;
    }
    int l = dfn[top[ret]] + 1, r = dfn[ret] + 1, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (Query(1, 1, n, mid, dfn[ret]) > vl)
        l = mid + 1;
      else
        r = mid;
    }
    ret = rec[l - 1];
    break;
  }
  if (!ret) ret = 1;
  u = x;
  Ans = 2 * (dep[x] - dep[ret]) + tm;
  int v = x;
  while (top[v] != top[ret]) {
    Update(1, 1, n, dfn[top[v]], dfn[v], Ans - dep[x]), v = fa[top[v]];
  }
  Update(1, 1, n, dfn[ret], dfn[v], Ans - dep[x]);
  return Ans;
}
bool cmp1(const Qry &a, const Qry &b) {
  return (dep[a.x] + a.tm == dep[b.x] + b.tm)
             ? (a.x < b.x)
             : (dep[a.x] + a.tm < dep[b.x] + b.tm);
}
int main() {
  int i;
  n = gi() + 1, m = gi();
  dep[1] = 1;
  memset(head, 0, sizeof(head));
  for (i = 2; i <= n; i++)
    fa[i] = gi() + 1, AddEdge(fa[i], i), dep[i] = dep[fa[i]] + 1;
  for (i = n; i >= 2; i--) {
    sz[i]++, sz[fa[i]] += sz[i];
    if (sz[i] > sz[son[fa[i]]]) son[fa[i]] = i;
  }
  dfs(1, 1);
  Build(1, 1, n);
  for (i = 1; i <= m; i++) q[i].x = gi() + 1, q[i].tm = gi(), q[i].id = i;
  sort(q + 1, q + m + 1, cmp1);
  for (i = 1; i <= m; i++) {
    ans[q[i].id] = Calc(q[i].x, q[i].tm);
  }
  for (i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}
