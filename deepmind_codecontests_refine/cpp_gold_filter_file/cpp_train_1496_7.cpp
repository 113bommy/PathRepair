#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[109];
int col[109];
int cntr;
int dfs(int v, int clr) {
  if (col[v] != -1) {
    if (col[v] != clr)
      return 0;
    else
      return 1;
  }
  col[v] = clr;
  if (clr == 1) cntr++;
  int i, j;
  for (i = 0; i < adj[v].size(); i++) {
    if (adj[v][i].second == 0) {
      if (!(dfs(adj[v][i].first, 1 - clr))) return 0;
    } else {
      if (!(dfs(adj[v][i].first, clr))) return 0;
    }
  }
  return 1;
}
int main() {
  int t, i, j, k, n, m;
  memset(col, -1, sizeof(col));
  scanf("%d", &n);
  scanf("%d", &m);
  int x, y, c;
  for (i = 0; i < m; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &c);
    adj[x].push_back(make_pair(y, c));
    adj[y].push_back(make_pair(x, c));
  }
  cntr = 0;
  for (i = 1; i <= n; i++) {
    if (col[i] == -1) {
      if (dfs(i, 0) == 0) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << cntr << endl;
  for (i = 1; i <= n; i++) {
    if (col[i] == 1) cout << i << " ";
  }
  cout << endl;
  return 0;
}
