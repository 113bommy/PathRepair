#include <bits/stdc++.h>
using namespace std;
const int INF = (is_same<int, long long>::value ? 1e18 + 666 : 1e9 + 666);
const long long INFll = 1e18 + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
inline int bpow(long long a, long long b, int mod) {
  int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = int((1ll * a * res) % mod);
      res %= mod;
    }
    a *= a;
    a %= mod;
  }
  return res;
}
void UseFiles(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void run();
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  run();
}
struct Dsu {
  vector<int> l, h;
  Dsu(int n) : l(n), h(n, 1) { iota(l.begin(), l.end(), 0); }
  int get_root(int v) {
    if (l[v] == v) return v;
    return l[v] = get_root(l[v]);
  }
  bool Union(int u, int v) {
    u = get_root(u);
    v = get_root(v);
    if (u == v) return false;
    if (h[u] > h[v]) {
      swap(u, v);
    }
    l[u] = v;
    h[v] += h[u];
    return true;
  }
};
struct Fenv {
  const int n;
  vector<int> tree;
  Fenv(int sz) : n(sz + 1), tree(n, 0) {}
  static int f(int i) { return i & -i; }
  int get(int idx) const {
    ++idx;
    int sm = 0;
    for (; idx > 0; idx -= f(idx)) {
      sm += tree[idx];
    }
    return sm;
  }
  void plus(int idx, int val) {
    ++idx;
    for (; idx < n; idx += f(idx)) {
      tree[idx] += val;
    }
  }
};
void run() {
  constexpr int maxlg = 19;
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  Dsu dsu(n);
  vector<char> ans(m, -1);
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    auto &[u, v, x] = edges[i];
    cin >> u >> v >> x;
    --u, --v;
    if (dsu.Union(u, v)) {
      g[u].push_back({v, x});
      g[v].push_back({u, x});
      ans[i] = 1;
    }
  }
  vector<int> xor_from_root(n, -1), tin(n, -1), sz(n, -1);
  vector<int> d(n, -1);
  vector<vector<int>> up(n, vector<int>(maxlg, -1));
  {
    int timer = 0;
    function<void(int, int, int, int)> dfs = [&](int v, int p, int xr,
                                                 int cur_d) {
      if (p == -1) {
        fill(up[v].begin(), up[v].end(), v);
      } else {
        up[v][0] = p;
        for (int i = 1; i < maxlg; ++i) {
          up[v][i] = up[up[v][i - 1]][i - 1];
        }
      }
      d[v] = cur_d;
      xor_from_root[v] = xr;
      tin[v] = timer++;
      int s = 1;
      for (auto &[u, x] : g[v]) {
        if (u == p) continue;
        dfs(u, v, xr ^ x, cur_d + 1);
        s += sz[u];
      }
      sz[v] = s;
    };
    for (int i = 0; i < n; ++i) {
      if (d[i] != -1) continue;
      dfs(i, -1, 0, 0);
    }
  }
  auto lca = [&d, &up](int u, int v) {
    if (d[u] < d[v]) {
      swap(u, v);
    }
    for (int i = maxlg - 1; i > -1; --i) {
      if (d[up[u][i]] >= d[v]) {
        u = up[u][i];
      }
    }
    if (u == v) {
      return u;
    }
    for (int i = maxlg - 1; i > -1; --i) {
      if (up[v][i] != up[u][i]) {
        v = up[v][i];
        u = up[u][i];
      }
    }
    return up[v][0];
  };
  Fenv f(n + 1);
  for (int i = 0; i < m; ++i) {
    if (ans[i] != -1) continue;
    auto [u, v, x] = edges[i];
    if ((xor_from_root[u] ^ xor_from_root[v] ^ x) == 0) {
      ans[i] = 0;
      continue;
    }
    int l = lca(u, v);
    if (f.get(tin[u]) + f.get(tin[v]) - 2 * f.get(tin[l]) != 0) {
      ans[i] = 0;
      continue;
    }
    ans[i] = 1;
    for (int uu = u; uu != l; uu = up[uu][0]) {
      f.plus(tin[uu], 1);
      f.plus(tin[uu] + sz[uu], -1);
    }
    for (int vv = v; vv != l; vv = up[vv][0]) {
      f.plus(tin[vv], 1);
      f.plus(tin[vv] + sz[vv], -1);
    }
  }
  for (auto &x : ans) {
    if (x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
