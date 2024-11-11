#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
int n, m;
bool e[16][16];
bool ok[17015][16][16], vis[17015];
vector<int> ans[17015];
vector<int> path[17015][16][16];
int pre[17015][5];
int con[17015][17], _b[17015];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i & 1 << j) {
        con[i][++con[i][0]] = j;
      }
    }
  }
  for (int i = 0; i < n; ++i) _b[1 << i] = i;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    e[u][v] = e[v][u] = 1;
    ans[1 << u | 1 << v].push_back(u * n + v);
    pre[1 << u | 1 << v][0] = 1;
    path[0][u][v].push_back(u * n + v);
    path[0][v][u].push_back(v * n + u);
    ok[0][u][v] = ok[0][v][u] = 1;
    vis[1 << u | 1 << v] = vis[1 << u] = vis[1 << v] = vis[0] = 1;
  }
  for (int mask = 0; mask < 1 << n; ++mask) {
    for (int u = 0; u < n; ++u) {
      if (mask & 1 << u) continue;
      for (int v = 0; v < n; ++v) {
        if (mask & 1 << v || u == v || !ok[mask][u][v]) continue;
        for (int z = 0; z < n; ++z) {
          if (mask & 1 << z || !e[v][z]) continue;
          int to_mask = mask | 1 << v;
          int bs = __builtin_popcount(to_mask);
          if (1 == bs && z == u) continue;
          if (ok[to_mask][u][z]) continue;
          path[to_mask][u][z] = path[mask][u][v];
          path[to_mask][u][z].push_back(v * n + z);
          ok[to_mask][u][z] = 1;
        }
      }
    }
  }
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (!vis[mask]) continue;
    if (pre[(1 << n) - 1][0] == n) break;
    for (int u = 0; u < n; ++u) {
      if (!(mask & 1 << u)) continue;
      for (int v = 0; v < n; ++v) {
        if (!(mask & 1 << v)) continue;
        if (__builtin_popcount(mask) == 2 && u == v) continue;
        int _mask = ~mask & (1 << n) - 1;
        int b = con[_mask][0];
        for (int i = 0; i < 1 << b; ++i) {
          int add_mask = 0, ti = i;
          while (ti) {
            int tt = ti & -ti;
            add_mask |= 1 << con[_mask][_b[tt]];
            ti -= tt;
          }
          if (!ok[add_mask][u][v]) continue;
          int to_mask = mask | add_mask;
          int siz = pre[mask][0] + path[add_mask][u][v].size();
          if (!vis[to_mask] || pre[to_mask][0] > siz) {
            pre[to_mask][0] = siz;
            pre[to_mask][1] = add_mask;
            pre[to_mask][2] = u;
            pre[to_mask][3] = v;
          }
          vis[to_mask] = 1;
        }
      }
    }
  }
  for (int mask = 1; mask < 1 << n; ++mask) {
    if (pre[mask][0] > 1) {
      int mask2 = pre[mask][1], u = pre[mask][2], v = pre[mask][3],
          mask1 = mask ^ mask2;
      for (auto x : ans[mask1]) ans[mask].push_back(x);
      for (auto x : path[mask2][u][v]) ans[mask].push_back(x);
    }
  }
  printf("%d\n", (int)ans[(1 << n) - 1].size());
  for (auto x : ans[(1 << n) - 1]) printf("%d %d\n", x / n + 1, x % n + 1);
  return 0;
}
