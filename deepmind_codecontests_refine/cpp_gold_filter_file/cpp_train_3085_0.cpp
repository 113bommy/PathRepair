#include <bits/stdc++.h>
using namespace std;
int vrt, edg;
void dfs1(int node, vector<int> &vis, vector<int> graph[],
          vector<vector<int> > &graph_d, vector<int> &vi, vector<int> &temp) {
  temp.push_back(node);
  vi[node - 1] = vis[node - 1] = 1;
  for (int i = 0; i < graph[node - 1].size(); ++i)
    if (vis[graph[node - 1][i] - 1] == 0)
      dfs1(graph[node - 1][i], vis, graph, graph_d, vi, temp);
}
void dfs_c1(int node, vector<int> &vi, vector<vector<int> > &graph_d,
            vector<int> graph[]) {
  if (vi[node - 1] != 0)
    return;
  else {
    vector<int> vis(vrt, 0), temp;
    dfs1(node, vis, graph, graph_d, vi, temp);
    graph_d.push_back(temp);
  }
}
int main() {
  int x, y;
  cin >> vrt >> edg;
  vector<int> graph[vrt];
  int cost[vrt];
  for (int i = 0; i < vrt; ++i) cin >> cost[i];
  long long price = 0;
  if (edg == 0) {
    for (int i = 0; i < vrt; ++i) price += cost[i];
    cout << price;
    return 0;
  }
  for (int i = 0; i < edg; ++i) {
    cin >> x >> y;
    graph[x - 1].push_back(y);
    graph[y - 1].push_back(x);
  }
  vector<vector<int> > graph_d;
  vector<int> vi(vrt, 0);
  for (int i = 0; i < vrt; ++i) dfs_c1(i + 1, vi, graph_d, graph);
  for (int i = 0; i < graph_d.size(); ++i) {
    int bribe_m = 10e9;
    for (int k = 0; k < graph_d[i].size(); ++k)
      bribe_m = min(bribe_m, cost[graph_d[i][k] - 1]);
    price += bribe_m;
  }
  cout << price;
}
