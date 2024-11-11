#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
vector<pair<int, int>> g[maxn];
bool mark[maxn];
int c[maxn];
int P = 1000000007;
bool dfs(int v, int col) {
  if (mark[v]) return c[v] == col;
  mark[v] = true;
  c[v] = col;
  bool ok = true;
  for (auto e : g[v]) {
    if (e.second == 0)
      ok &= dfs(e.first, 1 - col);
    else
      ok &= dfs(e.first, col);
  }
  return ok;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u, c;
    cin >> v >> u >> c;
    v--;
    u--;
    g[v].push_back(make_pair(u, c));
    g[u].push_back(make_pair(v, c));
  }
  int res = 0;
  bool ok = true;
  for (int i = 0; i < n && ok; i++)
    if (!mark[i]) {
      res++;
      ok &= dfs(i, 0);
    }
  int ans = 1;
  if (ok)
    for (int i = 1; i < res; i++) ans = ans * 2 % P;
  else
    ans = 0;
  cout << ans << endl;
  return 0;
}
