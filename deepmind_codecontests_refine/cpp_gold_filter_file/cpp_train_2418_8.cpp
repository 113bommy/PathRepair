#include <bits/stdc++.h>
const int maxn = 1.5e5 + 5;
inline long long max(long long a, long long b) { return a > b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
int n, cnt, a[maxn];
struct Line {
  long long k, b;
  Line(long long K = 0, long long B = 0) : k(K), b(B){};
  long long val(int x) { return k * x + b; }
} L[maxn * 40];
int mxid[maxn << 2];
void pushdown(int k, int l, int r, int id) {
  if (l == r) {
    if (L[id].val(l) > L[mxid[k]].val(l)) mxid[k] = id;
    return;
  }
  int mid = l + r >> 1;
  if (L[id].k > L[mxid[k]].k) {
    if (L[id].val(mid) > L[mxid[k]].val(mid))
      pushdown(k << 1, l, mid, mxid[k]), mxid[k] = id;
    else
      pushdown(k << 1 | 1, mid + 1, r, id);
  } else {
    if (L[id].val(mid) > L[mxid[k]].val(mid))
      pushdown(k << 1 | 1, mid + 1, r, mxid[k]), mxid[k] = id;
    else
      pushdown(k << 1, l, mid, id);
  }
}
long long Query(int k, int l, int r, int p) {
  if (l == r) return L[mxid[k]].val(p);
  int mid = l + r >> 1;
  return max(L[mxid[k]].val(p), (p <= mid ? Query(k << 1, l, mid, p)
                                          : Query(k << 1 | 1, mid + 1, r, p)));
}
int head[maxn], tot;
struct Edge {
  int next, to;
} e[maxn << 1];
void add_edge(int x, int y) {
  e[++tot].next = head[x];
  e[tot].to = y, head[x] = tot;
}
int vis[maxn], dep[maxn], siz[maxn], allsiz, maxmin, rt;
long long up[maxn], down[maxn], sum[maxn], ans;
void getinfo(int u, int rt, int F) {
  dep[u] = dep[F] + 1, siz[u] = 1;
  if (F)
    sum[u] = sum[F] + a[u], up[u] = up[F] + sum[u],
    down[u] = down[F] + 1ll * dep[u] * a[u];
  else
    sum[u] = up[u] = down[u] = 0;
  ans = max(ans, max(up[u] + 1ll * dep[u] * a[rt], down[u] + a[rt]));
  for (int i = head[u], v; v = e[i].to, i; i = e[i].next) {
    if (vis[v] || v == F) continue;
    getinfo(v, u, u), siz[u] += siz[v];
  }
}
void getcore(int u, int F) {
  int maxx = 0;
  siz[u] = 1;
  for (int i = head[u], v; v = e[i].to, i; i = e[i].next) {
    if (vis[v] || v == F) continue;
    getcore(v, u), siz[u] += siz[v], maxx = max(maxx, siz[v]);
  }
  maxx = max(maxx, allsiz - siz[u]);
  if (maxx < maxmin) maxmin = maxx, rt = u;
}
void getLine(int u, int F, int rt) {
  L[++cnt] = Line(sum[u] + a[rt], down[u] + a[rt]),
  pushdown(1, 0, siz[rt] - 1, cnt);
  for (int i = head[u], v; v = e[i].to, i; i = e[i].next)
    if (!vis[v] && v != F) getLine(v, u, rt);
}
void Merge(int u, int F, int rt) {
  ans = max(ans, Query(1, 0, siz[rt] - 1, dep[u] - 1) + up[u]);
  for (int i = head[u], v; v = e[i].to, i; i = e[i].next)
    if (!vis[v] && v != F) Merge(v, u, rt);
}
std::vector<int> tmp;
void getans(int u) {
  vis[u] = 1;
  tmp.clear();
  for (int i = head[u], v; v = e[i].to, i; i = e[i].next)
    if (!vis[v]) tmp.push_back(v);
  for (int i = 1; i <= 4 * siz[u]; ++i) mxid[i] = 0;
  for (int i = 0; i < tmp.size(); ++i)
    Merge(tmp[i], u, u), getLine(tmp[i], u, u);
  for (int i = 1; i <= 4 * siz[u]; ++i) mxid[i] = 0;
  for (int i = tmp.size() - 1; ~i; --i)
    Merge(tmp[i], u, u), getLine(tmp[i], u, u);
  for (int i = head[u], v; v = e[i].to, i; i = e[i].next) {
    if (vis[v]) continue;
    allsiz = siz[v], maxmin = 0x3f3f3f3f, getcore(v, 0), getinfo(rt, rt, 0),
    getans(rt);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; ++i)
    scanf("%d %d", &x, &y), add_edge(x, y), add_edge(y, x);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  allsiz = n, maxmin = 0x3f3f3f3f, getcore(1, 0), getinfo(rt, rt, 0),
  getans(rt);
  printf("%lld", ans);
  return 0;
}
