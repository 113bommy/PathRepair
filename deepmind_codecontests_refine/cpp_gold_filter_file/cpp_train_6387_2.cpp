#include <bits/stdc++.h>
using namespace std;
bool vis[(int)1e5];
int counter = 0;
int cnt = 0;
vector<vector<int>> vec(1e5);
bool dfs(int node, int par) {
  vis[node] = 1;
  cnt++;
  for (auto child : vec[node]) {
    if (vis[child] == 0) {
      dfs(child, node);
    } else if (child != par && vis[child] == 1) {
      return true;
    }
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      cnt = 0;
      if (dfs(i, -1) && cnt % 2 != 0) {
        counter++;
      }
    }
  }
  if ((n - counter) & 1)
    cout << counter + 1 << endl;
  else
    cout << counter << endl;
}
