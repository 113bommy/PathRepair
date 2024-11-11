#include <bits/stdc++.h>
using namespace std;
int n, k;
int64_t f[200005], d[200005][5], c[200005][5];
vector<int> g[200005];
void DFS(int u, int root) {
  int64_t dd[5], cc[5];
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v != root) {
      DFS(v, u);
      f[u] += f[v];
      for (int j = 0; j < k; j++) {
        dd[j] = d[v][(j - 1 + k) % k];
        cc[j] = c[v][(j - 1 + k) % k];
        if (j == 1 || k == 1) dd[j] += cc[j];
      }
      for (int j = 0; j < k; j++)
        for (int t = 0; t < k; t++) {
          f[u] += c[u][j] * dd[t] + d[u][j] * cc[t];
          if (j != 0 && t != 0 && j + t <= k) f[u] -= c[u][j] * cc[t];
        }
      for (int j = 0; j < k; j++) {
        d[u][j] += dd[j];
        c[u][j] += cc[j];
        f[u] += dd[j];
      }
    }
  }
  c[u][0]++;
}
int main() {
  cin >> n >> k;
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  DFS(1, 0);
  cout << f[1];
}
