#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct Bit {
  long long bit[maxn];
  void add(int i, long long x) {
    if (i == 0) return;
    while (i < maxn) bit[i] += x, i += (i & (-i));
  }
  long long qry(int i) {
    long long res = 0;
    while (i) res += bit[i], i -= (i & (-i));
    return res;
  }
  long long qry(int l, int r) {
    long long res = qry(r) - qry(l - 1);
    return res;
  }
} b1, b2;
vector<int> g[maxn];
int n;
void init() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
int dep[maxn], pa[maxn];
long long c[maxn], m[maxn];
int kk[maxn];
int son[maxn];
int dfn[maxn], id[maxn], idx = 0, out[maxn];
void get_dep(int u, int f) {
  dfn[id[u] = ++idx] = u;
  dep[u] = dep[f] + 1;
  pa[u] = f;
  for (int v : g[u])
    if (v ^ f) get_dep(v, u), c[u]++;
  out[u] = idx;
  son[u] = c[u];
}
struct node {
  int k, id;
  bool operator<(const node& a) const {
    if (k != a.k) return k > a.k;
    if (dep[id] != dep[a.id]) dep[id] > dep[a.id];
    return id < a.id;
  }
};
int fa[maxn];
int fnd(int x) { return x == fa[x] ? x : fa[x] = fnd(fa[x]); }
vector<int> opt[maxn];
vector<pair<int, int> > ask[maxn];
long long ans[maxn];
void sol() {
  get_dep(1, 0);
  set<node> s;
  for (int i = 1; i < n + 1; ++i) {
    fa[i] = i;
    if (c[i] == 0) continue;
    int k = (c[i] - 1) / (m[i] + 1);
    kk[i] = k;
    s.insert((node){k, i});
  }
  for (int cur = n; cur >= 0; --cur) {
    while (s.size() && (*s.begin()).k >= cur) {
      int u = (*s.begin()).id;
      opt[cur].push_back(u);
      s.erase(s.begin());
      fa[u] = pa[u];
      if (fnd(u) == 0) continue;
      int p = fnd(u);
      s.erase((node){kk[p], p});
      m[p] += m[u] + 1;
      c[p] += c[u] - 1;
      int k = min((c[p] - 1) / (m[p] + 1), (long long)cur);
      kk[p] = k;
      s.insert((node){kk[p], p});
    }
  }
  for (int i = 1; i < n + 1; ++i) c[i] = son[i], m[i] = 0, fa[i] = i;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int x, k;
    scanf("%d%d", &x, &k);
    ask[k].push_back(pair<int, int>(x, i));
  }
  for (int k = 200000; k >= 0; --k) {
    for (int u : opt[k]) {
      int p = fnd(pa[u]);
      long long cur_c = c[u] + b1.qry(id[u], out[u]);
      long long cur_m = m[u] + b2.qry(id[u], out[u]);
      c[p] += cur_c - 1;
      m[p] += cur_m + 1;
      int fp = pa[u];
      b1.add(id[fp], cur_c - 1);
      b2.add(id[fp], cur_m + 1);
      b1.add(id[p], -cur_c + 1);
      b2.add(id[p], -cur_m - 1);
      fa[u] = p;
    }
    for (pair<int, int> p : ask[k]) {
      int u, pos;
      tie(u, pos) = p;
      long long cur_c = c[u] + b1.qry(id[u], out[u]);
      long long cur_m = m[u] + b2.qry(id[u], out[u]);
      ans[pos] = cur_c - (long long)k * cur_m;
    }
  }
  for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
}
int main() {
  init();
  sol();
  return 0;
}
