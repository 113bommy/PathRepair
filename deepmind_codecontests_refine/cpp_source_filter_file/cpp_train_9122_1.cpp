#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9 + 5;
const double PI = acos(-1);
const int M = 1e6 + 5;
const int X[] = {1, -1, 0, 0};
const int Y[] = {0, 0, 1, -1};
const int mod = 1e9 + 7;
int n, m, dp[105][105][3][205];
vector<pair<int, int>> g[105];
bool dfs(int v1, int v2, int p, char x) {
  if (dp[v1][v2][p][x] != -1) {
    return dp[v1][v2][p][x];
  }
  if (p == 1) {
    for (int i = 0; i < g[v1].size(); i++) {
      int to = g[v1][i].first;
      char s = g[v1][i].second;
      if (s >= x && !dfs(to, v2, p ^ 1, s)) {
        return dp[v1][v2][p][x] = 1;
      }
    }
    return dp[v1][v2][p][x] = 0;
  } else {
    for (int i = 0; i < g[v2].size(); i++) {
      int to = g[v2][i].first;
      char s = g[v2][i].second;
      if (s >= x && !dfs(v1, to, p ^ 1, s)) {
        return dp[v1][v2][p][x] = 1;
      }
    }
    return dp[v1][v2][p][x] = 0;
    ;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    char x;
    cin >> u >> v >> x;
    g[u].push_back({v, x - 'a'});
  }
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        cout << 'B';
        continue;
      }
      if (dfs(i, j, 1, '*')) {
        cout << 'A';
      } else {
        cout << 'B';
      }
    }
    cout << "\n";
  }
  return 0;
}
