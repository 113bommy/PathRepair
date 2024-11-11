#include <bits/stdc++.h>
using namespace std;
bool okay, visited[100010], used[100010], visited2[100010];
int n, m;
vector<int> v[100010];
vector<int> vec;
vector<int> g[100010];
void dfs(int x) {
  visited[x] = 1;
  vec.push_back(x);
  for (int i = 0; i < (int)g[x].size(); i++) {
    if (!visited[g[x][i]]) dfs(g[x][i]);
  }
}
void dfs2(int x) {
  used[x] = 1;
  visited2[x] = 1;
  for (int i = 0; i < (int)v[x].size(); i++) {
    int child = v[x][i];
    if (used[child]) okay = true;
    if (!visited2[child]) dfs2(child);
  }
  used[x] = 0;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;
    v[first].push_back(second);
    g[first].push_back(second);
    g[second].push_back(first);
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      vec.clear();
      okay = false;
      dfs(i);
      for (int j = 0; j < (int)vec.size() && !okay; j++) {
        if (!visited2[vec[j]]) dfs2(vec[j]);
      }
      res += vec.size() - (!okay);
    }
  }
  cout << res << endl;
  return 0;
}
