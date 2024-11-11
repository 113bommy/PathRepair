#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g(5e5 + 7);
vector<int> h(5e5 + 7);
vector<vector<int>> len(5e5 + 7);
vector<int> p(5e5 + 7);
int n, m;
vector<int> used(5e5 + 7);
void dfs(int v, int hh) {
  h[v] = hh;
  len[hh].push_back(v);
  used[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    if (!used[g[v][i]]) {
      p[g[v][i]] = v;
      dfs(g[v][i], hh + 1);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) {
      g[i].clear();
      h[i] = 0;
      len[i].clear();
      used[i] = 0;
      p[i] = -1;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1, 0);
    if (len[(n + 1) / 2 - 1].size()) {
      cout << "Path\n";
      cout << n / 2 << "\n";
      int v = len[(n + 1) / 2 - 1][0];
      cout << v << " ";
      while (v != 1) {
        cout << p[v] << " ";
        v = p[v];
      }
      cout << "\n";
    } else {
      vector<pair<int, int>> ans;
      for (int i = 1; i < n; i++) {
        if (len[i].size() < 2) continue;
        for (int j = 0; j < len[i].size() - 1; j += 2) {
          ans.push_back({len[i][j], len[i][j + 1]});
        }
      }
      cout << "PAIRING\n" << ans.size() << "\n";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
      }
    }
  }
}
