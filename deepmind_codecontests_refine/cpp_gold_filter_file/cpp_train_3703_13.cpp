#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
struct graph {
  long long n;
  vector<vector<long long> > adj;
  graph() {}
  graph(long long n_) {
    n = n_;
    adj.resize(n);
  }
  void add(long long v, long long u) {
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
};
long long n;
graph g;
vector<long long> used;
vector<pair<long long, long long> > ps;
void dfs(long long v, long long c) {
  used[v] = c;
  for (long long u : g.adj[v]) {
    if (used[u]) {
      continue;
    }
    if (c == 1) {
      dfs(u, 2);
    } else {
      dfs(u, 1);
    }
  }
}
inline void solve() {
  for (long long i = 0; 2 * i < g.n; i++) {
    if (2 * i + 1 < g.n) {
      g.add(2 * i, 2 * i + 1);
    } else {
      g.add(2 * i, 0);
    }
  }
  used.assign(g.n, 0);
  for (long long i = 0; i < g.n; i++) {
    if (!used[i]) {
      dfs(i, 1);
    }
  }
  for (pair<long long, long long> p : ps) {
    cout << used[p.first] << " " << used[p.second] << "\n";
  }
}
inline void read() {
  cin >> n;
  g = graph(2 * n);
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    --a, --b;
    g.add(a, b);
    ps.push_back({a, b});
  }
}
