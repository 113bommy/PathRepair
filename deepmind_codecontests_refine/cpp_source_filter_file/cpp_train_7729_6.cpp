#include <bits/stdc++.h>
using namespace std;
using ill = long long;
class solution {
 public:
  void solve() {
    int tct;
    cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc) {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> g(n + 1);
      for (int c = 1; c <= m; ++c) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
      }
      vector<int> vis(n + 1, 0), ans;
      for (int u = 1; u <= n; ++u) {
        bool flg = true;
        for (auto v : g[u]) {
          if (flg == false) break;
          if (vis[u] == false) {
            for (auto k : g[v]) {
              if (flg == false) break;
              if (vis[k] == false) {
                vis[u] = true;
                ans.push_back(u);
                flg = false;
                break;
              }
            }
          }
        }
      }
      int siz = ans.size();
      cout << siz << '\n';
      for (int i = 0; i <= siz - 1; ++i) {
        if (i > 0) cout << ' ';
        cout << ans[i];
      }
      cout << '\n';
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  solution sln1;
  sln1.solve();
  cout.flush();
  return 0;
}
