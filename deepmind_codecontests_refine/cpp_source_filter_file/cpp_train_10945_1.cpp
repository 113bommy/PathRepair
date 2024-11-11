#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
bool visited[200005];
int m, n, x, y;
void dfs(int id) {
  for (int i = 0; i < v[id].size(); ++i) {
    if (visited[v[id][i]]) continue;
    cout << id << " " << v[id][i] << "\n";
    visited[v[id][i]] = 1;
    dfs(i);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int deg = 0, id = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg < (int)v[i].size()) deg = v[i].size(), id = i;
  }
  visited[id] = 1;
  for (int i = 0; i < v[id].size(); ++i) {
    visited[v[id][i]] = 1;
    cout << id << " " << v[id][i] << "\n";
  }
  for (int i = 0; i < v[id].size(); ++i) {
    dfs(v[id][i]);
  }
  return 0;
}
