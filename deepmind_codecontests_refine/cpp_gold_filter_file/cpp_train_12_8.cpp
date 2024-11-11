#include <bits/stdc++.h>
using namespace std;
const int maxn = 200500;
vector<int> side[maxn];
int n, m, val[maxn];
long long h[maxn], x[maxn], mx;
void dfs(int u) {
  if (val[u] != -1) return;
  bool vis[705] = {0};
  for (int i = 0; i < side[u].size(); i++) {
    int v = side[u][i];
    dfs(v);
    vis[val[v]] = 1;
  }
  for (int i = 0; i < 705; i++) {
    if (!vis[i]) {
      val[u] = i;
      break;
    }
  }
  x[val[u]] ^= h[u];
  mx = max(val[u] * 1ll, mx);
}
int main() {
  memset(val, -1, sizeof(val));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
  for (int i = 1, u, v; i <= m; i++)
    scanf("%d%d", &u, &v), side[u].push_back(v);
  for (int i = 1; i <= n; i++) dfs(i);
  for (int i = mx; i >= 0; i--) {
    if (x[i]) {
      printf("WIN\n");
      for (int j = 1; j <= n; j++) {
        if (val[j] == i && (h[j] ^ x[i]) < h[j]) {
          h[j] = h[j] ^ x[i];
          x[i] = 0;
          for (int k = 0; k < side[j].size(); k++) {
            int v = side[j][k];
            if (!x[val[v]]) continue;
            h[v] = h[v] ^ x[val[v]];
            x[val[v]] = 0;
          }
          break;
        }
      }
      for (int j = 1; j <= n; j++) printf("%lld ", h[j]);
      return 0;
    }
  }
  printf("LOSE\n");
  return 0;
}
