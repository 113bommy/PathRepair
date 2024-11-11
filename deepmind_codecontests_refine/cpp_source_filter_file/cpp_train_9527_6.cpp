#include <bits/stdc++.h>
using namespace std;
int cont = 0;
int n, m, z;
void dfs(vector<vector<vector<char> > >& graph,
         vector<vector<vector<bool> > >& visited, int x, int y, int k) {
  if (x < 0 || x >= n || y < 0 || y >= m || k < 0 || k >= z ||
      visited[x][y][k] || graph[x][y][k] == '#')
    return;
  visited[x][y][k] = true;
  cont++;
  dfs(graph, visited, x, y, k + 1);
  dfs(graph, visited, x, y, k - 1);
  dfs(graph, visited, x, y + 1, k);
  dfs(graph, visited, x, y - 1, k);
  dfs(graph, visited, x + 1, y, k);
  dfs(graph, visited, x - 1, y, k);
}
int main() {
  string temp;
  int x, y;
  cin >> z >> n >> m;
  vector<vector<vector<char> > > graph(
      z, vector<vector<char> >(n, vector<char>(m)));
  vector<vector<vector<bool> > > visited(
      z, vector<vector<bool> >(n, vector<bool>(m, false)));
  for (int i = 0; i < z; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> graph[i][j][k];
      }
    }
  }
  cin >> x >> y;
  dfs(graph, visited, x - 1, y - 1, 0);
  cout << cont;
}
