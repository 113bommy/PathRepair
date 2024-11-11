#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0, f = 1;
  char c = ' ';
  while (c < '0' || c > '9') f = c == '-' ? -1 : 1, c = getchar();
  while (c <= '9' && c >= '0') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int n, cnt, head[300005], to[300005 << 1], nxt[300005 << 1], m;
long long ans[300005];
int dep[300005], dfn[300005], rk[300005], son[300005], top[300005], fa[300005],
    siz[300005], num;
vector<int> vec[300005];
inline void add(int x, int y) {
  to[++cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
struct QWQ {
  int x, d, val;
  bool operator<(const QWQ &y) const { return dep[x] + d > dep[y.x] + y.d; }
} a[300005];
void dfs1(int u, int fat) {
  siz[u] = 1;
  int maxson = -1;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fat) continue;
    dep[v] = dep[u] + 1;
    fa[v] = u;
    vec[dep[v]].push_back(v);
    dfs1(v, u);
    siz[u] += siz[v];
    if (maxson < siz[v]) maxson = siz[v], son[u] = v;
  }
  return;
}
void dfs2(int u, int t) {
  dfn[u] = ++num;
  rk[num] = u;
  top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (!dfn[v]) dfs2(v, v);
  }
}
struct Node {
  long long sum, lazy;
  int l, r;
} node[300005 << 2];
inline void pushup(int cur) {
  node[cur].sum = node[cur << 1].sum + node[cur << 1 | 1].sum;
}
inline void pushdown(int cur) {
  if (!node[cur].lazy) return;
  int t = node[cur].lazy;
  node[cur].lazy = 0;
  node[cur << 1].sum += 1LL * (node[cur << 1].r - node[cur << 1].l + 1) * t;
  node[cur << 1].lazy += t;
  node[cur << 1 | 1].sum +=
      1LL * (node[cur << 1 | 1].r - node[cur << 1 | 1].l + 1) * t;
  node[cur << 1 | 1].lazy += t;
}
void build(int cur, int L, int R) {
  if (L == R) {
    node[cur].l = node[cur].r = L;
    return;
  }
  int mid = (L + R) >> 1;
  build(cur << 1, L, mid);
  build(cur << 1 | 1, mid + 1, R);
  node[cur].l = node[cur << 1].l;
  node[cur].r = node[cur << 1 | 1].r;
}
void update(int cur, int L, int R, int c) {
  if (L <= node[cur].l && node[cur].r <= R) {
    node[cur].sum += 1LL * (node[cur].r - node[cur].l + 1) * c;
    node[cur].lazy += c;
    return;
  }
  pushdown(cur);
  int mid = (node[cur].l + node[cur].r) >> 1;
  if (L <= mid) update(cur << 1, L, R, c);
  if (mid < R) update(cur << 1 | 1, L, R, c);
  pushup(cur);
}
long long query(int cur, int L, int R) {
  if (L <= node[cur].l && node[cur].r <= R) return node[cur].sum;
  pushdown(cur);
  int mid = (node[cur].l + node[cur].r) >> 1;
  long long res = 0;
  if (L <= mid) res += query(cur << 1, L, R);
  if (mid < R) res += query(cur << 1 | 1, L, R);
  return res;
}
int main() {
  n = rd();
  for (int i = 1; i < n; i++) {
    int x = rd(), y = rd();
    add(x, y);
    add(y, x);
  }
  m = rd();
  for (int i = 1; i <= m; i++) {
    a[i].x = rd(), a[i].d = rd(), a[i].val = rd();
  }
  dep[1] = 1;
  vec[1].push_back(1);
  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);
  sort(a + 1, a + m + 1);
  int mx = 0, pre;
  for (int i = 1; i <= n; i++) mx = max(mx, dep[i]);
  pre = mx;
  for (int i = 1; i <= m; i++) {
    int now = dep[a[i].x] + a[i].d;
    while (pre > now) {
      for (int j = 0; j < vec[pre].size(); j++) {
        int u = vec[pre][j];
        ans[u] = query(1, dfn[u], dfn[u]);
      }
      pre--;
    }
    update(1, dfn[a[i].x], dfn[a[i].x] + siz[a[i].x] - 1, a[i].val);
  }
  while (pre >= 1) {
    for (int j = 0; j < vec[pre].size(); j++) {
      int u = vec[pre][j];
      ans[u] = query(1, dfn[u], dfn[u]);
    }
    pre--;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
