#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > graph[200001];
vector<int> ans[200001];
int vis[200001] = {0}, v1;
void dfs(int u, int prev) {
  vis[u] = 1;
  int v, ind, k = 1;
  for (int j = 0; j < graph[u].size(); j++) {
    v = graph[u][j].first;
    ind = graph[u][j].second;
    if (!vis[v]) {
      if (k == prev) k++;
      ans[k].push_back(ind);
      dfs(v, k);
      k++;
    }
  }
}
int main() {
  int n, i, x, y, j;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    graph[x].push_back(pair<int, int>(y, i));
    graph[y].push_back(pair<int, int>(x, i));
  }
  dfs(1, -1);
  for (i = 1; i <= 200001; i++)
    if (ans[i].size() == 0) break;
  cout << i - 1 << endl;
  for (i = 1; i <= 200001; i++) {
    if (ans[i].size() == 0) break;
    cout << ans[i].size() << " ";
    for (j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
