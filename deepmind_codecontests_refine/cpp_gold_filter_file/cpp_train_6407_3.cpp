#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
std::vector<vector<long int>> g;
vector<long int> depth, parent, node;
bool cyclic = false;
void Dfs(long int N) {
  visited[N] = true;
  for (auto i : g[N]) {
    if (visited[i] == true && parent[N] != i) cyclic = true;
    if (!visited[i]) {
      visited[i] = true;
      parent[i] = N;
      node.push_back(i);
      Dfs(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n, m, x, y, i, j;
  cin >> n >> m;
  g.resize(n + 1);
  visited.resize(n + 1);
  parent.resize(n + 1, -1);
  node.push_back(1);
  for (i = 0; i < m; ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i = 0; i < n + 1; ++i) {
    visited[i] = false;
  }
  Dfs(1);
  if (cyclic == true || node.size() != n)
    cout << "no" << endl;
  else
    cout << "yes" << endl;
  return 0;
}
