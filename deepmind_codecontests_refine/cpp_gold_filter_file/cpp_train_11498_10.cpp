#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, c[N][N], edge[N][N], cnt[N][N], res[N][N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) c[i][j] = 1e9;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    c[u][v] = c[v][u] = edge[u][v] = edge[v][u] = w;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (edge[k][j] && c[i][k] + edge[k][j] == c[i][j]) cnt[i][j]++;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (c[i][k] + c[k][j] == c[i][j]) res[i][j] += cnt[i][k];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) cout << res[i][j] << ' ';
}
