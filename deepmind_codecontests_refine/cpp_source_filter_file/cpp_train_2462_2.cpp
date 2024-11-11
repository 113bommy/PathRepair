#include <bits/stdc++.h>
using namespace std;
vector<bool> used;
vector<int> d;
vector<vector<int>> g;
int cnt[1000000];
int t = 0;
void dfs(int v, int p) {
  d[v] = d[p] + 1;
  for (auto &u : g[v]) {
    dfs(u, v);
  }
}
signed main() {
  int n;
  cin >> n;
  g.resize(n + 1);
  d.resize(n + 1);
  used.resize(n, false);
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; ++i) {
    ++cnt[d[i]];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += cnt[i] % 2;
  }
  cout << ans << '\n';
}
