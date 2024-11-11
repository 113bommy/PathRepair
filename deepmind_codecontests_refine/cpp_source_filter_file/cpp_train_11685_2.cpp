#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
array<vector<int>, maxn> graph;
array<int, maxn> deg;
int maxDeg = 0;
vector<pair<int, int> > ans;
void put(int u, int t) { ans.push_back({u, t}); }
void dfs(int u, int p, int t) {
  int begT = t;
  put(u, t);
  for (const auto &v : graph[u]) {
    if (v == p) continue;
    if (t == maxDeg) {
      t -= deg[u];
      put(u, 0);
    }
    dfs(v, u, t + 1);
    put(u, t + 1);
    t++;
  }
  if (t >= begT) put(u, begT - 1);
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) maxDeg = max(maxDeg, deg[i]);
  dfs(1, 0, 0);
  ans.pop_back();
  cout << ans.size() << endl;
  for (const auto &step : ans) {
    cout << step.first << ' ' << step.second << endl;
  }
  return 0;
}
