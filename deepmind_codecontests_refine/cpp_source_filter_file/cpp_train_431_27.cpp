#include <bits/stdc++.h>
using namespace std;
const int minnodes = 1005;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[3 * n + 1];
    set<int> maxset;
    set<int> indset;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back({v, i + 1});
      g[v].push_back({u, i + 1});
    }
    set<int> vertices;
    for (int i = 1; i <= 3 * n; i++) vertices.insert(i);
    while (!vertices.empty()) {
      int start = *vertices.begin();
      vertices.erase(start);
      bool ch = 1;
      for (auto it : g[start]) {
        if (vertices.find(it.first) != vertices.end()) {
          maxset.insert(it.second);
          vertices.erase(it.first);
          ch = 0;
          break;
        }
      }
      if (ch) indset.insert(start);
    }
    if (indset.size() >= n) {
      int cnt = 0;
      cout << "Indset"
           << "\n";
      for (auto it : indset) {
        cout << it << " ";
        cnt++;
        if (cnt == n) break;
      }
    } else {
      cout << "Maxset"
           << "\n";
      int cnt = 0;
      for (auto it : maxset) {
        cout << it << " ";
        cnt++;
        if (cnt == n) break;
      }
    }
    cout << "\n";
  }
}
