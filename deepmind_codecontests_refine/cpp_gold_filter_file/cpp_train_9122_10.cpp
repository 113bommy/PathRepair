#include <bits/stdc++.h>
using namespace std;
long long n, m;
string s;
int MOD = 1e9 + 7;
vector<pair<int, int>> v;
vector<int> gr[102];
int dp[102][102][28], graph[102][102];
int DP(int u, int v, int w) {
  if (dp[u][v][w] >= 0) return dp[u][v][w];
  for (int i = 1; i <= n; i++) {
    if (graph[u][i] >= w && DP(v, i, graph[u][i]) == 0) return dp[u][v][w] = 1;
  }
  return dp[u][v][w] = 0;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m;
  memset(graph, -1, sizeof(graph));
  for (int i = 1; i <= m; i++) {
    int u, v;
    char w;
    cin >> u >> v >> w;
    graph[u][v] = w - 'a';
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      DP(i, j, 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (dp[i][j][0] ? 'A' : 'B');
    }
    cout << endl;
  }
  return 0;
}
