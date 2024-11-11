#include <bits/stdc++.h>
using namespace std;
int c[300010], v[300010], vis[300010];
int main() {
  int n, i, mn, ans, aux, at;
  vector<int> path;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &c[i]);
  for (i = 0; i < n; i++) scanf("%d", &v[i]), v[i]--;
  ans = 0;
  bool y;
  for (i = 0; i < n; i++) {
    if (vis[i]) continue;
    path.clear();
    at = i, aux = -1;
    while (1) {
      if (vis[at] == 1) break;
      if (vis[at] == 2) {
        aux = at;
        break;
      }
      vis[at] = 2;
      path.push_back(at);
      at = v[at];
    }
    y = 0, mn = 0x3F3F3F3F;
    for (i = 0; i < path.size(); i++) {
      if (path[i] == aux) y = 1;
      if (y) mn = min(mn, c[path[i]]);
      vis[path[i]] = 1;
    }
    if (y) ans += mn;
  }
  printf("%d\n", ans);
}
