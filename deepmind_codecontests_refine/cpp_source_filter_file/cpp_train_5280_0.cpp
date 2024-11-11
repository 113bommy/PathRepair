#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int a = -1;
int dfs(int u, int p) {
  int s = 0;
  for (int i = 0; i < g[u].size(); i++) {
    if (g[u][i] != p) {
      s += dfs(g[u][i], u);
    }
  }
  a += s % 2;
  return s + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int u, v;
  if (n % 2) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  dfs(1, 0);
  cout << a << endl;
  return 0;
}
