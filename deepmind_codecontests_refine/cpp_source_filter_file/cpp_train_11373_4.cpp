#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, x, y;
vector<int> edges[2][200005];
vector<set<int>> vs;
vector<vector<int>> vis;
bool dfs(int i, int j) {
  vis[j][i] = 1;
  for (auto e : edges[j][i]) {
    if (vis[j][e] == -1) return true;
    if (vis[j][e] == 1)
      continue;
    else {
      if (dfs(e, j)) return true;
      vis[j][e] = 1;
    }
  }
  vis[j][i] = 1;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vs = vector<set<int>>(n + 1);
  vis = vector<vector<int>>(2, vector<int>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    edges[0][a].push_back(b);
    edges[1][b].push_back(a);
  }
  vector<int> ans(n + 1, 0);
  string res(n, 'E');
  for (int i = 1; i < n + 1; ++i) {
    if (!vis[0][i] && !vis[1][i]) {
      ans[i] = 1;
      res[i - 1] = 'A';
    }
    for (int j = 0; j < 2; ++j) {
      if (!vis[j][i] && dfs(i, j)) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i < n + 1; ++i) cnt += ans[i];
  cout << cnt << "\n" << res << endl;
  return 0;
}
