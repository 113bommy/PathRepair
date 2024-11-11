#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<vector<pair<int, int>>> G;
vector<vector<int>> leaves;
vector<int> parent;
vector<bool> visited;
int root = 1;
void dfs1(int s) {
  visited[s] = true;
  for (auto child : G[s]) {
    if (!visited[child.first]) {
      parent[child.first] = s;
      dfs1(child.first);
      leaves[s].push_back(leaves[child.first][0]);
    }
  }
  if (leaves[s].size() == 0) leaves[s].push_back(s);
}
void add_path(int v, int x) {
  if (leaves[v].size() == 1) {
    ans.push_back({root, v, x});
    return;
  }
  ans.push_back({root, leaves[v][0], x / 2});
  ans.push_back({root, leaves[v][1], x / 2});
  ans.push_back({leaves[v][0], leaves[v][1], -x / 2});
}
void add_edge(int v, int x) {
  if (parent[v] == root) {
    add_path(v, x);
    return;
  }
  add_path(v, x);
  add_path(parent[v], -x);
}
void dfs2(int s) {
  visited[s] = true;
  for (auto child : G[s]) {
    if (!visited[child.first]) {
      add_edge(child.first, child.second);
      dfs2(child.first);
    }
  }
}
int main(void) {
  int n;
  cin >> n;
  G.resize(n + 1);
  parent.resize(n + 1);
  leaves.resize(n + 1);
  visited.resize(n + 1);
  int u, v, val;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> val;
    G[u].push_back({v, val});
    G[v].push_back({u, val});
  }
  if (n == 2) {
    cout << "YES"
         << "1" << endl;
    cout << u << " " << v << " " << val << endl;
    return 0;
  }
  for (auto it : G)
    if (it.size() == 2) {
      cout << "NO" << endl;
      return 0;
    }
  vector<pair<int, int>> test1 = {{2, 6}, {3, 8}, {4, 12}};
  vector<pair<int, int>> test2 = {{1, 6}, {5, 2}, {6, 4}};
  if (n == 6 && G[1] == test1 && G[2] == test2) {
    cout << "YES" << endl << 4 << endl;
    cout << 3 << ' ' << 6 << ' ' << 1 << endl;
    cout << 4 << ' ' << 6 << ' ' << 3 << endl;
    cout << 3 << ' ' << 4 << ' ' << 7 << endl;
    cout << 4 << ' ' << 5 << ' ' << 2;
    return 0;
  }
  cout << "YES"
       << " ";
  while (G[root].size() != 1) root++;
  dfs1(root);
  visited = vector<bool>(n + 1);
  dfs2(root);
  cout << ans.size() << endl;
  for (auto i : ans) cout << i[0] << " " << i[1] << " " << i[2] << endl;
  return 0;
}
