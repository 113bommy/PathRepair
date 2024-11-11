#include <bits/stdc++.h>
using namespace std;
map<int, map<int, long long> > dp2;
map<int, map<int, long long> > dp1;
vector<int> g[100100];
int a[100100];
void dfs(int u, int p) {
  if (dp2[u].count(p)) return;
  int i;
  long long p1 = 0, p2 = 0, p3 = 0;
  for (i = 0; i < g[u].size(); i++) {
    if (g[u][i] != p) {
      dfs(g[u][i], u);
      if (dp1[g[u][i]][u] > p1) {
        p2 = p1;
        p1 = dp1[g[u][i]][u];
      } else if (dp1[g[u][i]][u] > p2) {
        p2 = dp1[g[u][i]][u];
      }
      if (dp2[g[u][i]][u] > p3) p3 = dp2[g[u][i]][u];
    }
  }
  dp2[u][p] = max(p3, p1 + p2 + a[u]);
  dp1[u][p] = p1 + a[u];
}
int main() {
  int n, i;
  long long x, y, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      int v = g[i][j];
      dfs(i, v);
      dfs(v, i);
      ans = max(ans, dp2[i][v] + dp2[v][i]);
    }
  }
  cout << ans << endl;
}
