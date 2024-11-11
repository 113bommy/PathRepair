#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int n, m, k;
int ls;
bool vis[N];
vector<pair<int, int> > e[N];
void dfs(int u, int sum, int x) {
  if (u > n) {
    ls++;
    return;
  }
  if (ls >= k) {
    return;
  }
  dfs(u + 1, sum, x);
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int w = e[u][i].first, v = e[u][i].second;
    if (sum + w <= x && !vis[v]) {
      vis[v] = 1;
      dfs(u + 1, sum + w, x);
      vis[v] = 0;
    }
  }
}
bool ok(int x) {
  ls = 0;
  memset(vis, 0, sizeof(vis));
  dfs(1, 0, x);
  return ls >= k;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < (m); ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    e[u].push_back({w, v});
  }
  int l = 0, r = 100000;
  while (l + 1 < r) {
    int mid = l + r >> 1;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  int ans = -1;
  if (ok(l) || ok(r)) ans = ok(l) ? l : r;
  printf("%d\n", ans);
  return 0;
}
