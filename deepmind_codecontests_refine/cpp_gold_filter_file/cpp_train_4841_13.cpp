#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
vector<int> adj[MAXN];
int match[MAXN], l[MAXN];
bool visited[MAXN], found;
int n, m, p;
void DFS(int u) {
  for (int i = 0; i <= (int)(adj[u].size()) - 1; ++i) {
    int v = adj[u][i];
    if (!visited[v]) {
      visited[v] = true;
      if (match[v] != 0)
        DFS(match[v]);
      else
        found = true;
      if (found) {
        match[v] = u;
        return;
      }
    }
  }
}
int matching() {
  for (int i = 1; i <= m; ++i) match[i] = 0;
  for (int i = 1; i <= n; ++i) l[i] = i;
  int nlist = n, old = 0;
  do {
    old = nlist;
    for (int i = 1; i <= m; ++i) visited[i] = false;
    for (int i = nlist; i >= 1; --i) {
      found = false;
      DFS(l[i]);
      if (found) {
        l[i] = l[nlist];
        nlist--;
      }
    }
  } while (old != nlist);
  return (n - nlist);
}
bool choose[MAXN], elim[MAXN];
vector<int> g[2 * MAXN];
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    int k, v;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &v);
      if (v > 0)
        g[v].push_back(i);
      else
        g[m - v].push_back(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (g[i].size() == 2) {
      choose[i] = true;
      elim[g[i][0]] = elim[g[i][1]] = true;
    }
    if (g[i + m].size() == 2) {
      elim[g[i + m][0]] = elim[g[i + m][1]] = true;
    }
  }
  int nelim = 0;
  for (int i = 1; i <= n; i++) nelim += elim[i];
  for (int i = 1; i <= m; i++) {
    for (int j : g[i]) {
      if (!elim[j]) adj[i].push_back(j);
    }
    for (int j : g[i + m]) {
      if (!elim[j]) adj[i].push_back(j);
    }
  }
  int _n = n, _m = m;
  n = _m;
  m = _n;
  int l = matching();
  if (l != m - nelim) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (match[i] != 0) {
      int u = match[i];
      if ((g[u].size() > 0) && (g[u][0] == i)) choose[u] = true;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) printf("%d", ((choose[i]) ? 1 : 0));
}
