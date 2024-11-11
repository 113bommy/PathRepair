#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct edge {
  int from, to;
  edge() {}
  edge(int _1, int _2) : from(_1), to(_2) {}
};
edge edges[N * 2];
int head[N], nxt[N * 2], tot;
inline void init() {
  memset(head, -1, sizeof(head));
  tot = 0;
}
inline void add_edge(int x, int y) {
  edges[tot] = edge(x, y);
  nxt[tot] = head[x];
  head[x] = tot++;
}
long long w[N];
int father[N][21], dep[N], son[N], siz[N], top[N];
int dfn[N], idfn[N], dfs_clock;
long long val[N][21];
void dfs_1(int x, int fa, int depth) {
  father[x][0] = fa;
  dep[x] = depth;
  siz[x] = 1;
  son[x] = -1;
  for (int i = 1; (1 << i) <= dep[x]; i++) {
    father[x][i] = father[father[x][i - 1]][i - 1];
    val[x][i] = val[x][i - 1] + val[father[x][i - 1]][i - 1];
  }
  for (int i = head[x]; ~i; i = nxt[i]) {
    edge& e = edges[i];
    if (e.to != fa) {
      val[e.to][0] = w[x];
      dfs_1(e.to, x, depth + 1);
      siz[x] += siz[e.to];
      if (son[x] == -1 || siz[son[x]] < siz[e.to]) son[x] = e.to;
    }
  }
}
void dfs_2(int x, int tp) {
  dfn[x] = ++dfs_clock;
  idfn[dfn[x]] = x;
  top[x] = tp;
  if (son[x] != -1) dfs_2(son[x], tp);
  for (int i = head[x]; ~i; i = nxt[i]) {
    edge& e = edges[i];
    if (e.to != father[x][0] && e.to != son[x]) dfs_2(e.to, e.to);
  }
}
struct SegmentTree {
  int sumv[N << 2], tag[N << 2];
  inline void downtag(int cur, int v, int l, int r) {
    tag[cur] += v;
    sumv[cur] += v * (r - l + 1);
  }
  inline void pushdown(int cur, int l, int r) {
    if (tag[cur]) {
      int mid = (l + r) >> 1;
      downtag((cur << 1), tag[cur], l, mid);
      downtag((cur << 1 | 1), tag[cur], mid + 1, r);
      tag[cur] = 0;
    }
  }
  inline void maintain(int cur) {
    sumv[cur] = sumv[(cur << 1)] + sumv[(cur << 1 | 1)];
  }
  void update(int cur, int l, int r, int ql, int qr, int v) {
    if (ql == l && qr == r)
      downtag(cur, v, l, r);
    else {
      pushdown(cur, l, r);
      int mid = (l + r) >> 1;
      if (qr <= mid)
        update((cur << 1), l, mid, ql, qr, v);
      else if (ql > mid)
        update((cur << 1 | 1), mid + 1, r, ql, qr, v);
      else
        update((cur << 1), l, mid, ql, mid, v),
            update((cur << 1 | 1), mid + 1, r, mid + 1, qr, v);
      maintain(cur);
    }
  }
  int query(int cur, int l, int r, int p) {
    if (l == r)
      return sumv[cur];
    else {
      int mid = (l + r) >> 1;
      pushdown(cur, l, r);
      if (p <= mid)
        return query((cur << 1), l, mid, p);
      else
        return query((cur << 1 | 1), mid + 1, r, p);
    }
  }
} seg;
int n;
int L;
long long S;
void Change(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    seg.update(1, 1, n, dfn[top[x]], dfn[x], 1);
    x = father[top[x]][0];
  }
  if (dep[x] > dep[y]) swap(x, y);
  seg.update(1, 1, n, dfn[x], dfn[y], 1);
}
int Get(int x) {
  int u = x;
  long long sum = w[x];
  for (int i = 20; i >= 0; i--)
    if (father[u][i] && dep[u] - dep[father[x][i]] + 1 <= L &&
        sum + val[u][i] <= S) {
      sum += val[u][i];
      u = father[u][i];
    }
  return u;
}
priority_queue<pair<int, int> > q;
int main() {
  scanf("%d %d %I64d", &n, &L, &S);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &w[i]);
    if (w[i] > S) {
      puts("-1");
      return 0;
    }
  }
  init();
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    add_edge(x, i);
  }
  dfs_1(1, 0, 1);
  dfs_2(1, 1);
  for (int i = 1; i <= n; i++)
    if (son[i] == -1) q.push(make_pair(dep[i], i));
  int Ans = 0;
  while (!q.empty()) {
    pair<int, int> now = q.top();
    q.pop();
    if (seg.query(1, 1, n, dfn[now.second])) continue;
    int x = Get(now.second);
    Change(now.second, x);
    Ans++;
    if (father[x][0]) q.push(make_pair(dep[father[x][0]], father[x][0]));
  }
  printf("%d\n", Ans);
  return 0;
}
