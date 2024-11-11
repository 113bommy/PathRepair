#include <bits/stdc++.h>
using namespace std;
inline int next_int() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const int maxn = 2e5 + 10;
vector<pair<int, int> > g[maxn];
int res[maxn];
int ans;
inline void dfs(int node, int father = -1, int preCol = -1) {
  int curCol = 0;
  for (auto u : g[node]) {
    if (u.first == father) continue;
    if (curCol == preCol) {
      curCol++;
    }
    res[u.second] = curCol++;
    dfs(u.first, node, res[u.second]);
  }
}
vector<int> vc[maxn];
int32_t main() {
  int n = next_int();
  for (int i = 0; i < n - 1; i++) {
    int v = next_int() - 1, u = next_int() - 1;
    g[v].push_back({u, i}), g[u].push_back({v, i});
    ans = max(ans, (int)max(g[v].size(), g[u].size()));
  }
  dfs(0);
  cout << ans << "\n";
  for (int i = 0; i < n - 1; i++) vc[res[i]].push_back(i + 1);
  for (int i = 0; i < ans; i++) {
    cout << vc[i].size() << " ";
    for (auto edges : vc[i]) cout << edges << " ";
    cout << "\n";
  }
}
