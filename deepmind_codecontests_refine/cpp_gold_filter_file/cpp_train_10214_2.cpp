#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > g;
bool used[1001] = {false};
void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < g[v].size(); i++)
    if (!used[g[v][i]]) {
      int to = g[v][i];
      dfs(to);
    }
}
int main() {
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (!used[i]) {
      cout << "NO" << endl;
      return (0);
    }
  if (n == m)
    cout << "FHTAGN!";
  else
    cout << "NO";
}
