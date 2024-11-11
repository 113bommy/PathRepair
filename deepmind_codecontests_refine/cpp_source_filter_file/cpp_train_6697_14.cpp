#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(50001);
int d[50001][501];
int n, k, ans;
void dfs(int v, int p) {
  d[v][0] = 1;
  for (auto to : g[v]) {
    if (to != p) {
      dfs(to, v);
      for (int i = 0; i <= k; ++i) {
        ans += d[v][i] * d[to][k - i - 1];
      }
      for (int i = 0; i <= k; ++i) {
        d[v][i] = d[to][i - 1];
      }
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(1, 0);
  cout << ans * 2;
}
