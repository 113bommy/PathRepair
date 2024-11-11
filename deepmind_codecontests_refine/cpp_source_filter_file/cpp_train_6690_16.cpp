#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, m;
vector<vector<long long> > g(N, vector<long long>());
vector<long long> d(N), last(N);
vector<long long> path;
long long k = 0;
vector<bool> in_path(N, 0);
vector<pair<long long, long long> > pairs;
long long p = 0;
void dfs(long long v, long long l) {
  d[v] = l;
  if (last[l] != -1) {
    pairs.push_back({last[l] + 1, v + 1});
    last[l] = -1;
    p++;
  } else {
    last[l] = v;
  }
  for (auto u : g[v]) {
    if (d[u] == 0) {
      dfs(u, l + 1);
      if (in_path[u]) {
        path.push_back(v + 1);
        k++;
        in_path[v] = 1;
      }
    }
  }
  if (d[v] >= (n + 1) / 2 && !in_path[v] && k == 0) {
    path.push_back(v + 1);
    k++;
    in_path[v] = 1;
  }
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 1);
  if (k >= (n + 1) / 2) {
    cout << "PATH\n";
    cout << k << "\n";
    for (long long i = 0; i < k; ++i) {
      cout << path[i] << ' ';
    }
    cout << "\n";
  } else {
    cout << "PAIRING\n";
    cout << p << "\n";
    for (long long i = 0; i < p; ++i) {
      cout << pairs[i].first << ' ' << pairs[i].second << "\n";
    }
  }
  for (long long i = 0; i <= n; ++i) {
    g[i].clear();
    d[i] = 0;
    last[i] = -1;
    in_path[i] = 0;
  }
  path.clear();
  pairs.clear();
  k = 0;
  p = 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
