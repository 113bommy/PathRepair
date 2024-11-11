#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
bool vis[100005];
bool tree;
void dfs(int n, int p) {
  vis[n] = true;
  for (int i = 0; i < v[n].size(); i++) {
    if (!vis[v[n][i]])
      dfs(v[n][i], n);
    else if (v[n][i] != p)
      tree = false;
  }
}
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int x = 0;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      tree = true;
      dfs(i, 0);
      if (tree) x++;
    }
  }
  cout << x;
  return 0;
}
