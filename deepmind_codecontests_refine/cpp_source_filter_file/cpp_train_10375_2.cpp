#include <bits/stdc++.h>
using namespace std;
const long long nax = 1e5 + 1;
vector<long long> g[nax], add, best(nax, 0), lvl(nax, 0);
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long n;
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long root = 1;
  function<void(long long, long long)> dfs_dp = [&](long long v, long long p) {
    vector<long long> temp;
    best[v] = 1;
    for (auto &u : g[v]) {
      if (u != p) {
        dfs_dp(u, v);
        best[v] = max(best[u] + 1, best[v]);
        temp.push_back(best[u]);
      }
    }
    bool f = 0;
    for (auto &i : temp) {
      if (i == best[v] - 1 && !f)
        f = 1;
      else
        add.push_back(i);
    }
    return;
  };
  long long mx = 0;
  function<void(long long, long long)> root_decider = [&](long long v,
                                                          long long p) {
    lvl[v] = lvl[p] + 1;
    if (mx < lvl[v]) {
      mx = lvl[v];
      root = v;
    }
    for (auto &u : g[v]) {
      if (u != p) {
        root_decider(u, v);
      }
    }
    return;
  };
  root_decider(1, 0);
  dfs_dp(root, 0);
  add.push_back(best[root]);
  cout << "1 ";
  sort(add.begin(), add.end(), greater<long long>());
  long long sum = 0;
  long long cur = 0;
  while (cur < (long long)(add.size())) {
    sum += add[cur++];
    cout << sum << ' ';
  }
  while (cur++ < n) cout << n << ' ';
}
