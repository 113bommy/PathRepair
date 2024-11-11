#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
vector<int> g[10004];
int vis[10004];
int mat[10004];
inline bool kuhn(int x, int now) {
  if (vis[x] == now) return 0;
  vis[x] = now;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (mat[y] == -1 || kuhn(mat[y], now)) {
      mat[y] = x;
      return 1;
    }
  }
  return 0;
}
pair<int, pair<int, int> > edge[100005];
int cst[100005];
int main() {
  int n, m, x, y, z, cnt = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d %d %d", &edge[i].second.first, &edge[i].second.second,
          &edge[i].first);
  sort(edge, edge + m);
  for (int i = 0; i < m; i++) {
    cst[++cnt] = edge[i].first;
    x = edge[i].first;
    while (i < m && edge[i].first == x) i++;
    i--;
  }
  int lo = 1, hi = cnt, res = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 0; i < m && edge[i].first <= cst[mid]; i++)
      g[edge[i].second.first].emplace_back(edge[i].second.second);
    memset(mat, -1, sizeof mat);
    memset(vis, 0, sizeof vis);
    bool f = 1;
    for (int i = 1; i <= n && f; i++) f = kuhn(i, i);
    if (f)
      res = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  printf("%d\n", res);
  return 0;
}
