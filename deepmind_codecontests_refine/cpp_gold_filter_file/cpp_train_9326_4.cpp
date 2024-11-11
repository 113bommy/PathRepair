#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
map<int, int> mp;
int lc[maxn], rc[maxn], a[maxn], n, mx, vis[maxn];
void dfs(int u, int l, int r) {
  if (!(~u) || l > r) return;
  if (l < a[u] && a[u] < r) mp[a[u]] = 1;
  dfs(lc[u], l, min(r, a[u]));
  dfs(rc[u], max(a[u], l), r);
}
int main() {
  int ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", a + i, lc + i, rc + i), mx = max(mx, a[i]);
    if (~lc[i]) vis[lc[i]] = 1;
    if (~rc[i]) vis[rc[i]] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      dfs(i, -1, 1e9 + 1);
      break;
    }
  for (int i = 1; i <= n; ++i)
    if (!mp[a[i]]) ++ans;
  printf("%d\n", ans);
  return 0;
}
