#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> radj[n];
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      adj[x].push_back(y);
      radj[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) sort(adj[i].begin(), adj[i].end());
    vector<int> p(n, 0);
    vector<int> d;
    for (int i = 0; i < n; ++i) {
      for (int v : radj[i]) {
        p[i] = max(p[i], p[v] + 1);
      }
      if (p[i] == 2) {
        p[i] = -1;
        d.push_back(i);
      }
    }
    cout << d.size() << '\n';
    for (auto r : d) cout << r + 1 << ' ';
    cout << '\n';
  }
}
