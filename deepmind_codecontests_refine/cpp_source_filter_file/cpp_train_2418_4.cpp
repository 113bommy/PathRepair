#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void chkmin(T &a, const T &b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, const T &b) {
  a = a > b ? a : b;
}
const int MAXN = 150005, MAXT = 300005;
int sz[MAXN], val[MAXN], vis[MAXN], n, tot;
vector<int> gra[MAXN];
struct Tree {
  long long k, b;
  Tree *ls, *rs;
  bool did;
} nd[MAXT], *rt;
vector<Tree *> cls;
long long ans;
Tree *build(int l, int r) {
  Tree *cur = nd + (tot++);
  cur->did = false;
  if (l == r) return cur;
  int mid = (l + r) >> 1;
  cur->ls = build(l, mid);
  cur->rs = build(mid + 1, r);
  return cur;
}
void modify(long long k, long long b, int l = 1, int r = n, Tree *p = rt) {
  if (p->did) {
    long long f1 = p->k * l + p->b, f2 = p->k * r + p->b, g1 = k * l + b,
              g2 = k * r + b;
    if (g1 >= f1 && g2 >= f1) {
      p->k = k, p->b = b;
      return;
    } else if (g1 <= f1 && g2 <= f2)
      return;
    double in = 1.0 * (b - p->b) / (k - p->k);
    int mid = (l + r) >> 1;
    if (in <= mid) {
      if (f1 >= g1 && f2 <= g2) {
        modify(p->k, p->b, l, mid, p->ls);
        p->k = k, p->b = b;
      } else
        modify(k, b, l, mid, p->ls);
    } else {
      if (f1 <= g1 && f2 >= g2) {
        modify(p->k, p->b, mid + 1, r, p->rs);
        p->k = k, p->b = b;
      } else
        modify(k, b, mid + 1, r, p->rs);
    }
  } else
    p->k = k, p->b = b, p->did = true, cls.push_back(p);
}
long long query(int x, int l = 1, int r = n, Tree *p = rt) {
  if (!p->did) return -1e18;
  int mid = (l + r) >> 1;
  long long res = p->k * x + p->b;
  if (x <= mid)
    chkmax(res, query(x, l, mid, p->ls));
  else
    chkmax(res, query(x, mid + 1, r, p->rs));
  return res;
}
void get_sz(int u, int fa) {
  sz[u] = 1;
  for (int v : gra[u])
    if (v != fa && !vis[v]) {
      get_sz(v, u);
      sz[u] += sz[v];
    }
}
pair<int, int> get_rt(int u, int fa, int s) {
  auto res = make_pair(MAXN, MAXN);
  int mn = s;
  for (int v : gra[u])
    if (v != fa && !vis[v]) {
      res = min(res, get_rt(v, u, s + sz[u] - sz[v]));
      chkmax(mn, sz[v]);
    }
  return min(res, make_pair(mn, u));
}
void dfs1(int u, int fa, int dep, long long sum, long long cur, long long tmp) {
  sum += val[u], cur += sum, ++dep, tmp += (long long)dep * val[u];
  chkmax(ans, cur), chkmax(ans, tmp);
  chkmax(ans, query(dep) + cur);
  for (int v : gra[u])
    if (v != fa && !vis[v]) dfs1(v, u, dep, sum, cur, tmp);
}
void dfs2(int u, int fa, int dep, long long sum, long long cur) {
  ++dep, sum += val[u], cur += (long long)dep * val[u];
  modify(sum, cur);
  for (int v : gra[u])
    if (v != fa && !vis[v]) dfs2(v, u, dep, sum, cur);
}
void divide(int u) {
  get_sz(u, 0);
  u = get_rt(u, 0, 0).second;
  vis[u] = 1;
  for (int v : gra[u])
    if (!vis[v]) {
      dfs1(v, u, 1, val[u], val[u], val[u]);
      dfs2(v, u, 0, 0, 0);
    }
  for (Tree *p : cls) p->did = false;
  cls.clear();
  reverse(gra[u].begin(), gra[u].end());
  for (int v : gra[u])
    if (!vis[v]) {
      dfs1(v, u, 1, val[u], val[u], val[u]);
      dfs2(v, u, 0, 0, 0);
    }
  for (Tree *p : cls) p->did = false;
  cls.clear();
  for (int v : gra[u])
    if (!vis[v]) divide(v);
  vis[u] = 0;
}
int main() {
  scanf("%d", &n);
  rt = build(1, n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    gra[u].push_back(v);
    gra[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) scanf("%d", val + i);
  divide(1);
  printf("%lld\n", ans);
  return 0;
}
