#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int, char>>> v;
short dp[105][105][2][27];
bool solve(int node1, int node2, bool player, int last) {
  if (dp[node1][node2][player][last] != -1)
    return dp[node1][node2][player][last];
  bool win = 0;
  if (player == 0) {
    for (int i = 0; i < v[node1].size(); i++) {
      int u = v[node1][i].first;
      char x = v[node1][i].second;
      if (x >= last) win = max(win, !solve(u, node2, !player, x));
    }
  } else {
    for (int i = 0; i < v[node2].size(); i++) {
      int u = v[node2][i].first;
      char x = v[node2][i].second;
      if (x >= last) win = max(win, !solve(node1, u, !player, x));
    }
  }
  return dp[node1][node2][player][last] = win;
}
int main() {
  memset(dp, -1, sizeof dp);
  int m;
  cin >> n >> m;
  v.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    char s;
    cin >> x >> y >> s;
    v[x].push_back({y, 'A' + s - 'a'});
  }
  char ans[n + 5][n + 5];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i][j] = 'A' + !solve(i, j, 0, 0);
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
