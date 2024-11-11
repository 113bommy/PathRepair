#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  int n;
  cin >> n;
  int graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = INF;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b] = graph[b][a] = c;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (graph[0][i] != INF) ans = max(ans, graph[0][i]);
  }
  cout << ans << "\n";
}
