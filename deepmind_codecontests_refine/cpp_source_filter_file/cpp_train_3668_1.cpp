#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, color[N], diff[N], res[N];
vector<int> g[N];
void DFS1(int u, int parent) {
  diff[u] = (color[u] == 1 ? 1 : -1);
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == parent) continue;
    DFS1(v, u);
    if (diff[v] > 0) {
      diff[u] += diff[v];
    }
  }
}
void DFS2(int u, int parent) {
  if (u == 1)
    res[1] = diff[1];
  else {
    if (diff[u] >= 0)
      res[u] = max(res[parent], diff[u]);
    else
      res[u] = max(diff[u] + res[parent], diff[u]);
  }
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == parent) continue;
    DFS2(v, u);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> color[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  DFS1(1, 0);
  DFS2(1, 0);
  for (int i = 1; i <= n; i++) cout << res[i] << ' ';
  return 0;
}
