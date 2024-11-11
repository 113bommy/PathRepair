#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<pair<int, bool> > >& Graph, vector<int>& visited,
        vector<bool>& is_enemy, int root, int idx, bool& is_valid) {
  if (is_enemy[root]) is_valid = false;
  visited[root] = idx;
  int count = 1;
  for (auto a : Graph[root])
    if (!a.second && visited[a.first] != idx)
      is_enemy[a.first] = true;
    else if (!a.second && visited[a.first] == idx)
      is_valid = false;
    else if (a.second && visited[a.first] == -1) {
      count += dfs(Graph, visited, is_enemy, a.first, idx, is_valid);
    }
  return count;
}
int main(void) {
  int n, m, k;
  cin >> n >> k;
  vector<vector<pair<int, bool> > > Graph(n);
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    Graph[u].push_back(make_pair(v, 1));
    Graph[v].push_back(make_pair(u, 1));
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    Graph[u].push_back(make_pair(v, 0));
    Graph[v].push_back(make_pair(u, 0));
  }
  int result = 0;
  vector<int> visited(n, -1);
  for (int i = 0; i < n; ++i)
    if (visited[i] == -1) {
      vector<bool> is_enemy(n, false);
      bool is_valid = true;
      int tmp = dfs(Graph, visited, is_enemy, i, i, is_valid);
      if (is_valid) result = max(result, tmp);
    }
  cout << result << endl;
  return 0;
}
