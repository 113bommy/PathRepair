#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200010;
int n, k;
int deg[NMAX], deg2[NMAX];
vector<pair<int, int> > g[NMAX];
int ans[NMAX];
int dfs(int u, int fa, int e) {
  if (deg2[u] > deg[n - k]) {
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].first, id = g[u][i].second;
      if (fa == v) continue;
      ans[id] = e;
      dfs(v, u, e);
    }
  } else {
    int tmp = 0;
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].first, id = g[u][i].second;
      if (fa == v) continue;
      tmp += 1;
      if (tmp == e) tmp += 1;
      ans[id] = tmp;
      dfs(v, u, tmp);
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(make_pair(v, i));
    g[v].push_back(make_pair(u, i));
    deg[u] += 1, deg[v] += 1;
    deg2[u] += 1, deg2[v] += 1;
  }
  sort(deg + 1, deg + 1 + n);
  dfs(1, -1, 1);
  printf("%d\n", deg[n - k]);
  for (int i = 1; i < n; i++) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}
