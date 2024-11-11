#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
const int inf = 100000005;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = graph[v][u] = 1;
    indegree[u]++;
    indegree[v]++;
  }
  int res = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (graph[i][j]) {
        for (int k = j + 1; k <= n; k++) {
          if (graph[i][k] && graph[j][k])
            res = min(res, indegree[i] + indegree[j] + indegree[k]);
        }
      }
    }
  }
  if (res == inf)
    cout << -1 << "\n";
  else
    cout << res - 6 << "\n";
  return 0;
}
