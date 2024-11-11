#include <bits/stdc++.h>
using namespace std;
int d[1000002][11], g[1000002][6];
int v[5000];
bool vis[1000002], bad[1000002];
int us[20];
int sz;
int dfs(int v) {
  vis[v] = 1;
  ++sz;
  for (int i = 1; i <= g[v][0]; ++i) {
    int u = g[v][i];
    if (!vis[u]) dfs(u);
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", v + i);
  sort(v, v + n);
  int m, mxe = (k + 1) * k, mxm = v[n - 1] - v[0];
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int df = v[j] - v[i];
      if (d[df][0] == mxe / 2)
        bad[df] = 1;
      else
        d[df][++d[df][0]] = v[j];
    }
  for (m = 2;; ++m) {
    int cnt = 0;
    for (int j = m; j <= mxm && cnt <= mxe; j += m) {
      if (!bad[j])
        for (int l = 1, a, b; l <= d[j][0] && cnt <= mxe; ++l) {
          a = d[j][l], b = d[j][l] - j;
          us[cnt++] = a;
          us[cnt++] = b;
          g[a][++g[a][0]] = b;
          g[b][++g[b][0]] = a;
        }
      else
        cnt = mxe + 1;
    }
    if (cnt <= mxe) {
      int ans = 0;
      for (int i = 0; i < cnt; ++i)
        if (!vis[us[i]]) {
          sz = 0;
          dfs(us[i]);
          ans += sz - 1;
        }
      if (ans <= k) break;
    }
    for (int i = 0; i < cnt; ++i) g[us[i]][0] = vis[us[i]] = 0;
  }
  printf("%d\n", m);
  return 0;
}
