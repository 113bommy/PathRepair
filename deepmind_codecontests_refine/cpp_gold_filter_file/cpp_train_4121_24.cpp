#include <bits/stdc++.h>
using namespace std;
long long x[50], y[50];
vector<vector<int>> g;
long long dx[4] = {-1, 1, 0, 0};
long long dy[4] = {0, 0, -1, 1};
void dfs(int v, int prev, long long val, int dir) {
  int cur = 0;
  for (auto to : g[v]) {
    if (to != prev) {
      if (cur == dir) cur++;
      x[to] = x[v] + val * dx[cur];
      y[to] = y[v] + val * dy[cur];
      dfs(to, v, val / 2, cur ^ 1);
      cur++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() > 4) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  dfs(1, 0, 1 << 30, -1);
  for (int i = 1; i <= n; i++) {
    cout << x[i] << " " << y[i] << endl;
  }
}
