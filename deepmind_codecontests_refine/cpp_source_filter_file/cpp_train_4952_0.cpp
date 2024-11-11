#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, k, u, v, c[200005] = {}, d[200005] = {}, z = 0;
  vector<int> g[200005] = {};
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 0; i < m; i++)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  for (int i = 1; i <= k; i++) {
    if (d[i]) continue;
    d[i] = 1;
    queue<int> q;
    vector<int> w = {i};
    q.push(i);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int j = 0; j < g[x].size(); j++) {
        if (!d[g[x][j]]) d[g[x][j]] = 1, q.push(g[x][j]), w.push_back(g[x][j]);
      }
    }
    unordered_map<int, int> p;
    int o = 0;
    for (int j = 0; j < w.size(); j++) p[c[w[j]]]++, o = max(o, p[c[w[j]]]);
    z += w.size() - o;
  }
  cout << z;
}
