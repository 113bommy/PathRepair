#include <bits/stdc++.h>
using namespace std;
const long long nax = 5e5 + 1;
vector<long long> g[nax], par(nax), dep(nax);
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) g[i].clear(), par[i] = -1, dep[i] = -1;
    for (long long i = 1; i <= m; i++) {
      long long u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long nodeCan = -1;
    function<void(long long)> dfs_tree = [&](long long v) {
      for (auto &u : g[v]) {
        if (dep[u] == -1) {
          dep[u] = dep[v] + 1;
          if (dep[u] + 1 == (n + 1) / 2) nodeCan = u;
          par[u] = v;
          dfs_tree(u);
        }
      }
    };
    dep[1] = 0;
    dfs_tree(1);
    if (nodeCan == -1) {
      cout << "PAIRING\n";
      cout << ((n + 1) / 2) / 2 << "\n";
      vector<long long> last(n + 1, -1);
      long long done = ((n + 1) / 2) / 2;
      for (long long i = 1; i <= n; i++) {
        if (!done) break;
        if (last[dep[i]] == -1)
          last[dep[i]] = i;
        else {
          cout << last[dep[i]] << " " << i << "\n";
          last[dep[i]] = -1;
          done--;
        }
      }
    } else {
      cout << "PATH\n";
      cout << (n + 1) / 2 << "\n";
      while (nodeCan != -1) {
        cout << nodeCan << " ";
        nodeCan = par[nodeCan];
      }
      cout << "\n";
    }
  }
}
