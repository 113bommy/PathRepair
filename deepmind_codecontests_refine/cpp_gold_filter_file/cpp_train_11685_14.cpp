#include <bits/stdc++.h>
using namespace std;
int n, D;
vector<vector<int> > adj;
vector<int> deg;
void dfs(int u, int p = 0, int t = 0) {
  cout << u << ' ' << t << '\n';
  int tt = t;
  if (t == D && p != 0) {
    t -= deg[u];
    cout << u << ' ' << t << '\n';
  }
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, t + 1);
    cout << u << ' ' << ++t << '\n';
    if (t == D && p != 0) {
      t -= deg[u];
      cout << u << ' ' << t << '\n';
    }
  }
  if (t > tt - 1 && p != 0) cout << u << ' ' << tt - 1 << '\n';
}
void solve() {
  cin >> n;
  adj = vector<vector<int> >(n + 1, vector<int>());
  deg = vector<int>(n + 1);
  for (int i = (0); i < (n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = (0); i < (n + 1); ++i) deg[i] = int(adj[i].size());
  D = *max_element(deg.begin(), deg.end());
  cout << 3 * n - 2 << '\n';
  dfs(1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
