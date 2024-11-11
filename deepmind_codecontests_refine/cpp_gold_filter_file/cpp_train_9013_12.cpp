#include <bits/stdc++.h>
using namespace std;
vector<int> result, visited;
vector<vector<int> > graph, vertices;
struct compare {
  bool operator()(int const &a, int const &b) { return result[a] < result[b]; }
};
void dfs(int node, int res) {
  if (visited[node]) return;
  visited[node] = 1;
  int p1, p2, sz, colour;
  sort(vertices[node].begin(), vertices[node].end(), compare());
  colour = res;
  p2 = vertices[node].size() - 1;
  for (p1 = 0; p1 < vertices[node].size(); p1++) {
    if (result[vertices[node][p1]]) continue;
    while (p2 >= 0 && result[vertices[node][p2]] == colour) {
      colour--;
      p2--;
    }
    result[vertices[node][p1]] = colour;
    colour--;
  }
  for (p1 = 0; p1 < graph[node].size(); p1++) dfs(graph[node][p1], res);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  int p1, p2, n, m, c, u, v, res = 0, x;
  cin >> n >> m;
  result.resize(m, 0);
  visited.resize(n, 0);
  graph.resize(n);
  vertices.resize(n);
  for (p1 = 0; p1 < n; p1++) {
    cin >> c;
    res = max(res, c);
    for (p2 = 0; p2 < c; p2++) {
      cin >> x;
      x--;
      vertices[p1].push_back(x);
    }
  }
  for (p1 = 0; p1 < n - 1; p1++) {
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (p1 = 0; p1 < n; p1++) dfs(p1, res);
  cout << max(res, 1) << endl;
  for (p1 = 0; p1 < m; p1++) cout << max(result[p1], 1) << " ";
  return 0;
}
