#include <bits/stdc++.h>
using namespace std;
const int SIZE = 555;
const long double eps = 1e-12;
long double dp[SIZE][SIZE];
long double ans[SIZE];
void gauss(int n, long double a[][SIZE]) {
  vector<bool> vis(n, false);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (vis[j]) continue;
      if (fabs(a[j][i]) > eps) {
        vis[i] = true;
        for (int k = 0; k <= n; ++k) swap(a[i][k], a[j][k]);
        break;
      }
    }
    if (fabs(a[i][i]) < eps) continue;
    for (int j = 0; j <= n; ++j) {
      if (i != j && fabs(a[j][i]) > eps) {
        long double res = a[j][i] / a[i][i];
        for (int k = 0; k <= n; ++k) a[j][k] -= a[i][k] * res;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i] = a[i][n] / a[i][i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  --a, --b;
  vector<int> deg(n, 0);
  vector<long double> p(n, 0);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u], ++deg[v];
  }
  for (auto& i : p) {
    cin >> i;
  }
  auto mapp = [&](int x, int y) { return x * n + y; };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int p1 = mapp(i, j);
      dp[p1][p1] = 1.0 - p[i] * p[j] * (i != j);
      for (auto u : g[i]) {
        for (auto v : g[j]) {
          if (u == v) continue;
          int p2 = mapp(u, v);
          dp[p1][p2] = -(1.0 - p[u]) / deg[u] * (1.0 - p[v]) / deg[v];
        }
      }
      for (auto u : g[i]) {
        if (u == j) continue;
        int p2 = mapp(u, j);
        dp[p1][p2] = -(1.0 - p[u]) / deg[u] * p[j];
      }
      for (auto v : g[j]) {
        if (i == v) continue;
        int p2 = mapp(i, v);
        dp[p1][p2] = -(1.0 - p[v]) / deg[v] * p[i];
      }
    }
  }
  int s = mapp(a, b);
  dp[s][n * n] += 1;
  gauss(n * n, dp);
  for (int i = 0; i < n; i++) {
    int p = mapp(i, i);
    cout << fixed << setprecision(10) << ans[p] << " \n"[i == n - 1];
  }
  return 0;
}
