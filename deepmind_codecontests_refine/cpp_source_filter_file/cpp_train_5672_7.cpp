#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T& a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T& a, Args&... args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007;
constexpr long long M9 = 1000000009;
constexpr long long MFFT = 998244353;
constexpr double PI = 3.14159265358979323846;
template <class T>
void outv(const T& a, char d = ' ', bool nl = false) {
  for (auto& x : a) cout << x << d;
  if (nl) cout << '\n';
}
static mt19937_64 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
auto __fast_io__ = (ios_base::sync_with_stdio(false), cin.tie(nullptr));
const long long LOG = 17;
struct dsu {
  vector<int32_t> sz;
  vector<int32_t> p;
  int32_t setCnt;
  void merge(int32_t v, int32_t u) {
    sz[v] += sz[u];
    p[u] = v;
    setCnt--;
  }
  explicit dsu(int32_t n) {
    sz.assign(n, 1);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    setCnt = n;
  }
  int32_t get(int32_t v) {
    if (p[v] == v) {
      return v;
    }
    return p[v] = get(p[v]);
  }
  bool unite(int32_t v, int32_t u) {
    v = get(v);
    u = get(u);
    if (v == u) {
      return false;
    }
    if (sz[v] < sz[u]) {
      swap(v, u);
    }
    merge(v, u);
    return true;
  }
  bool inOneSet(int32_t v, int32_t u) { return get(v) == get(u); }
};
int32_t main() {
  long long n;
  __read(n);
  vector<vector<pair<long long, long long>>> g(n);
  for (long long i = 1; i < n; ++i) {
    long long v, u, w;
    __read(v, u, w);
    v--, u--;
    g[v].emplace_back(u, w);
    g[u].emplace_back(v, w);
  }
  vector<long long> dist(n);
  auto bfs = [&](long long sv) {
    fill(dist.begin(), dist.end(), -1);
    dist[sv] = 0;
    queue<long long> q;
    q.push(sv);
    while (!q.empty()) {
      long long v = q.front();
      q.pop();
      for (auto [u, w] : g[v]) {
        if (dist[u] == -1) {
          dist[u] = dist[v] + w;
          q.push(u);
        }
      }
    }
  };
  bfs(0);
  long long sv = max_element(dist.begin(), dist.end()) - dist.begin();
  bfs(sv);
  long long ev = max_element(dist.begin(), dist.end()) - dist.begin();
  vector<vector<long long>> up(n, vector<long long>(LOG));
  vector<long long> deep(n);
  function<void(long long, long long)> dfs = [&](long long v, long long p) {
    up[v][0] = p;
    for (long long i = 1; i < LOG; ++i) {
      up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto& [u, w] : g[v]) {
      if (u != p) {
        deep[u] = deep[v] + 1;
        dist[u] = dist[v] + w;
        dfs(u, v);
      }
    }
  };
  dist[0] = 0;
  dfs(0, 0);
  auto shift = [&](long long v, long long sh) {
    for (long long i = 0; i < LOG; ++i) {
      if ((sh >> i) & 1) {
        v = up[v][i];
      }
    }
    return v;
  };
  auto lca = [&](long long v, long long u) {
    if (deep[v] < deep[u]) swap(v, u);
    v = shift(v, deep[v] - deep[u]);
    if (v == u) return v;
    for (long long i = LOG - 1; i >= 0; --i) {
      if (up[v][i] != up[u][i]) {
        v = up[v][i];
        u = up[u][i];
      }
    }
    return up[v][0];
  };
  auto calc_dist = [&](long long v, long long u) {
    long long p = lca(v, u);
    return dist[v] + dist[u] - 2 * dist[p];
  };
  vector<long long> d(n);
  for (long long v = 0; v < n; ++v) {
    d[v] = max(calc_dist(v, sv), calc_dist(v, ev));
  }
  vector<long long> o(n);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(),
       [&](long long i, long long j) { return d[i] > d[j]; });
  long long q;
  __read(q);
  while (q--) {
    long long b;
    __read(b);
    dsu ds(n);
    long long r = 0;
    long long ans = 1;
    for (long long l = 0; l < n; ++l) {
      while (r < n && d[o[l]] - d[o[r]] <= b) {
        long long v = o[r];
        for (auto& [u, w] : g[v]) {
          if (d[v] < d[u]) {
            ds.unite(v, u);
          }
        }
        ans = max(ans, (long long)ds.sz[ds.get(v)]);
        r++;
      }
      ds.sz[ds.get(o[l])]--;
    }
    cout << ans << '\n';
  }
  return 0;
}
