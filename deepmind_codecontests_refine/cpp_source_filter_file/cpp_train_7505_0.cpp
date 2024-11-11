#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
struct printer {
  ~printer() { cerr << endl; }
  template <class c>
  printer& operator,(c x) {
    cerr << boolalpha << x;
    return *this;
  }
  printer& operator,(string x) {
    cerr << x;
    return *this;
  }
  template <class c, class d>
  printer& operator,(pair<c, d> x) {
    return *this, "(", x.first, ", ", x.second, ")";
  }
  template <class... d, template <class...> class c>
  printer& operator,(c<d...> x) {
    return *this, range(begin(x), end(x));
  }
  template <class c>
  printer& operator,(rge<c> x) {
    *this, "[";
    for (auto it = x.b; it != x.e; ++it) *this, (it == x.b ? "" : ", "), *it;
    return *this, "]";
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
const int N = 2e5 + 100, LOG = 20;
vector<int> g[N];
int Timer;
int st[N], en[N];
int depth[N];
int par[N][LOG];
void dfs(int u, int p, int d = 0) {
  st[u] = ++Timer;
  par[u][0] = p;
  depth[u] = d;
  for (int k = 1; k < LOG; k++) {
    if (par[u][k - 1] != -1)
      par[u][k] = par[par[u][k - 1]][k - 1];
    else
      par[u][k] = -1;
  }
  for (int v : g[u]) {
    if (v != p) dfs(v, u, d + 1);
  }
  en[u] = Timer;
}
int LCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int d = depth[u] - depth[v];
  for (int k = LOG - 1; k >= 0; k--) {
    if ((d >> k) & 1) {
      u = par[u][k];
    }
  }
  if (u == v) return u;
  for (int k = LOG - 1; k >= 0; k--) {
    if (par[u][k] != par[v][k]) {
      u = par[u][k];
      v = par[v][k];
    }
  }
  return par[u][0];
}
int kth_par(int u, int k) {
  for (int i = LOG - 1; i >= 0; i--) {
    if ((k >> i) & 1) u = par[u][i];
  }
  return u;
}
struct node {
  int mx, mx_cnt;
  node() {}
  node(int a, int b) { mx = a, mx_cnt = b; }
} tr[4 * N];
node Merge(node l, node r) {
  node m;
  if (l.mx > r.mx)
    m = l;
  else if (l.mx < r.mx)
    m = r;
  else
    m = l, m.mx_cnt += r.mx_cnt;
  return m;
}
int inf = 1e9;
int lz[4 * N];
void build(int cn, int b, int e) {
  tr[cn].mx = 0;
  tr[cn].mx_cnt = e - b + 1;
  if (b == e) return;
  int lc = 2 * cn, rc = lc + 1, mid = (b + e) >> 1;
  build(lc, b, mid);
  build(rc, mid + 1, e);
}
void propagate(int u, int st, int en) {
  if (!lz[u]) return;
  tr[u].mx += lz[u];
  if (st != en) {
    lz[2 * u] += lz[u];
    lz[2 * u + 1] += lz[u];
  }
  lz[u] = 0;
}
void update(int u, int st, int en, int l, int r, int x) {
  propagate(u, st, en);
  if (r < st || en < l)
    return;
  else if (l <= st && en <= r) {
    lz[u] += x;
    propagate(u, st, en);
  } else {
    int mid = (st + en) / 2;
    update(2 * u, st, mid, l, r, x);
    update(2 * u + 1, mid + 1, en, l, r, x);
    tr[u] = Merge(tr[2 * u], tr[2 * u + 1]);
  }
}
node query(int u, int st, int en, int l, int r) {
  propagate(u, st, en);
  if (r < st || en < l)
    return node(-inf, 0);
  else if (l <= st && en <= r)
    return tr[u];
  else {
    int mid = (st + en) / 2;
    return Merge(query(2 * u, st, mid, l, r),
                 query(2 * u + 1, mid + 1, en, l, r));
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  build(1, 1, n);
  set<pair<int, int>> cur_edges;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (make_pair(depth[u], u) < make_pair(depth[v], v)) swap(u, v);
    int add;
    if (cur_edges.count({u, v}))
      add = -1, cur_edges.erase({u, v});
    else
      add = +1, cur_edges.insert({u, v});
    int lca = LCA(u, v);
    if (v == lca) {
      update(1, 1, n, st[1], en[1], +add);
      int vc = kth_par(u, depth[u] - depth[v] - 1);
      update(1, 1, n, st[vc], en[vc], -add);
      update(1, 1, n, st[u], en[u], +add);
    } else {
      update(1, 1, n, st[u], st[u], +add);
      update(1, 1, n, st[v], en[v], +add);
    }
    auto res = query(1, 1, n, 1, n);
    int ans = 0;
    if (res.mx == cur_edges.size()) ans = res.mx_cnt;
    cout << ans << "\n";
  }
}
