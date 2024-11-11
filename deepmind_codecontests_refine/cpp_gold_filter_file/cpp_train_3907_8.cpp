#include <bits/stdc++.h>
using namespace std;
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
template <typename T>
void _F(const char *name, T arg1) {
  cerr << name << " = " << arg1 << '\n';
}
template <typename T, typename... Args>
void _F(const char *names, T arg1, Args... args) {
  const char *name = strchr(names, ',');
  cerr.write(names, name - names) << " = " << arg1 << '\n';
  _F(name + 2, args...);
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &q) {
  in >> q.first >> q.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &q) {
  out << q.first << " " << q.second;
  return out;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2) {
  return {p1.first - p2.first, p1.second - p2.second};
}
const long long N = 1e5 + 1;
std::vector<long long> g[N], vis(N);
std::vector<long long> tim[N];
long long n, m, u, v, l, t;
long long sub[N], h[N], sum[N], tot[N];
long long tin[N], tout[N], up[N][20];
long long val[2 * N];
bool is_ancestor(long long u, long long v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
long long lca(long long u, long long v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  if (is_ancestor(v, u)) {
    return v;
  }
  for (long long i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void dfs1(long long v, long long p) {
  vis[v] = sub[v] = 1;
  tin[v] = ++t;
  up[v][0] = p;
  for (long long i = 1; i <= l; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  for (auto u : g[v]) {
    if (!vis[u]) {
      h[u] = h[v] + 1;
      dfs1(u, v);
      sub[v] += sub[u];
      sum[v] += sum[u] + sub[u];
    }
  }
  tout[v] = ++t;
  val[tin[v]] = v;
}
void dfs(long long v, long long p, long long t) {
  tot[v] = t + (n - sub[v]);
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v, tot[v] + sum[v] - sum[u] - sub[u]);
    }
  }
}
void solve() {
  cin >> n >> m;
  l = ceil(log2(n));
  for (long long i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 1);
  dfs(1, 1, 0);
  for (long long i = 1; i <= n; i++) {
    tot[i] = tot[i] + sum[i];
    for (auto u : g[i]) {
      tim[i].push_back(tin[u]);
    }
    sort((tim[i]).begin(), (tim[i]).end());
  }
  double ans = 0;
  for (long long i = 0; i < m; i++) {
    cin >> u >> v;
    long long p = lca(u, v);
    double t;
    if (p == v) swap(u, v);
    if (p == u) {
      long long j =
          (long long)(lower_bound((tim[u]).begin(), (tim[u]).end(), tin[v]) -
                      begin(tim[u]));
      if (j == (long long)((tim[u]).size()) || tim[u][j] != tin[v]) j--;
      long long y = val[tim[u][j]];
      long long x = tot[u] - sum[y] - sub[y];
      long long tmp = (sub[v] * (n - sub[y])) * (h[v] - h[u] + 1) +
                      sum[v] * (n - sub[y]) + x * sub[v];
      t = (double)tmp;
      t = t / (sub[v] * (n - sub[y]));
    } else {
      long long tmp = (sub[v] * sub[u]) * (h[v] - 2 * h[p] + h[u] + 1) +
                      sum[v] * sub[u] + sum[u] * sub[v];
      t = (double)tmp;
      t = t / (sub[v] * sub[u]);
    }
    cout << t << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  start = clock();
  cout << fixed << setprecision(20);
  for (long long i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
