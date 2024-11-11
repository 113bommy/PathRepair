#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> g[N];
int n, m, par[N], l[N];
void dfs(int v, int p = 0) {
  for (auto u : g[v]) {
    if (l[u] != -1) continue;
    l[u] = l[v] + 1, par[u] = v;
    dfs(u, v);
  }
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) g[i].clear(), l[i] = -1;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    l[1] = 0;
    dfs(1);
    int ok = 0;
    vector<int> v[(n + 1) / 2];
    for (int i = 1; i <= n; i++) {
      if (l[i] < (n + 1) / 2)
        v[l[i]].push_back(i);
      else {
        ok = 1;
        int c = i;
        cout << "PATH\n" << l[i] + 1 << "\n" << c << ' ';
        while (c != 1) {
          c = par[c];
          cout << c << " ";
        }
        cout << '\n';
        break;
      }
    }
    if (ok) continue;
    vector<pair<int, int> > ans;
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < (int)v[i].size() - 1; j += 2)
        ans.push_back({v[i][j], v[i][j + 1]});
    }
    cout << "PAIRING\n" << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
  }
}
