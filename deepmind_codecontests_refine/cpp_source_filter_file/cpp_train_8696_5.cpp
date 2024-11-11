#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &g, int v, int p, int &cnt,
         vector<int> &wt, int tw) {
  cnt++;
  for (int i = 0; i < g[v].size(); i++) {
    if (g[v][i].first == p) continue;
    if ((tw + g[v][i].second) <= wt[g[v][i].first])
      dfs(g, g[v][i].first, v, cnt, wt, max(tw + g[v][i].second, 0));
  }
  return;
}
int main() {
  int n;
  cin >> n;
  vector<int> wt(n + 1);
  for (int i = 1; i <= n; i++) cin >> wt[i];
  vector<vector<pair<int, int>>> g(n + 1);
  int a, b;
  for (int i = 2; i <= n; i++) {
    cin >> a >> b;
    g[a].push_back({i, b});
    g[i].push_back({a, b});
  }
  int cnt = 1;
  dfs(g, 1, 0, cnt, wt, 0);
  cout << cnt << endl;
}
