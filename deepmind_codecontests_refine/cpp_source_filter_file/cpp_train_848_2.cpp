#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> adj(3 * n);
    vector<pair<long long, long long>> edges(m);
    for (long long i = 0; i < m; ++i) {
      long long u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges[i] = {u, v};
    }
    vector<bool> used(3 * n, false);
    vector<bool> edgeMatching(m, false);
    long long numE = 0;
    for (long long i = 0; i < m; ++i) {
      if (!used[edges[i].first] && !used[edges[i].second]) {
        edgeMatching[i] = true;
        used[edges[i].first] = true;
        used[edges[i].second] = true;
        ++numE;
      }
    }
    if (numE >= n) {
      cout << "Matching\n";
      long long cnt = 0;
      for (long long i = 0; i < m; ++i) {
        if (edgeMatching[i]) {
          cout << i + 1 << ' ';
          ++cnt;
        }
        if (cnt == n) break;
      }
      cout << '\n';
    } else {
      cout << "IndSet\n";
      long long cnt = 0;
      for (long long i = 0; i < 3 * n; ++i) {
        if (used[i]) {
          cout << i + 1 << ' ';
          ++cnt;
        }
        if (cnt == n) break;
      }
      cout << '\n';
    }
  }
}
