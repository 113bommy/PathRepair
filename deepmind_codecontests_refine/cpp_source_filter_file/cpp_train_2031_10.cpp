#include <bits/stdc++.h>
using namespace std;
long long dp[15][1 << 15];
int e[15][15];
int a[105], b[105], c[105];
int n, m, q;
bool inline in(int x, int y) { return (1 << x) & y; }
int dfs(int u, int st) {
  if (dp[u][st] != -1) return dp[u][st];
  dp[u][st] = 0;
  int lft = st - (1 << u);
  int pt;
  for (int i = 0; i < n; i++) {
    if (in(i, lft)) {
      pt = i;
      break;
    }
  }
  for (int s = lft; s; s = (s - 1) & lft) {
    if (!in(pt, s)) continue;
    int f = 1;
    for (int i = 0; i < n; i++) {
      if (i == u) continue;
      for (int j = 0; j < n; j++) {
        if (j == u) continue;
        if (e[j][i] && (in(i, s) ^ in(j, s))) {
          f = 0;
          break;
        }
      }
      if (!f) break;
    }
    if (!f) continue;
    for (int i = 1; i <= q; i++) {
      if (c[i] == u && in(a[i], s) && in(b[i], s)) f = 0;
      if (in(c[i], s) && (!in(a[i], s) || !in(b[i], s))) f = 0;
      if (!f) break;
    }
    if (!f) continue;
    int cnt = 0, son;
    for (int i = 0; i < n; i++) {
      if (e[u][i] && in(i, s)) {
        cnt++;
        son = i;
      }
    }
    if (cnt >= 2) continue;
    if (cnt == 1)
      dp[u][st] += dfs(son, s) * dfs(u, st ^ s);
    else {
      for (int i = 0; i < n; i++) {
        if (!in(i, s)) continue;
        dp[u][st] += dfs(i, s) * dfs(u, st ^ s);
      }
    }
  }
  return dp[u][st];
}
int main() {
  while (cin >> n >> m >> q) {
    int x, y;
    memset(e, 0, sizeof(e));
    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
      x--, y--;
      e[x][y] = e[y][x] = 1;
    }
    for (int i = 1; i <= q; i++) {
      cin >> a[i] >> b[i] >> c[i];
      a[i]--, b[i]--, c[i]--;
    }
    int all = (1 << n) - 1;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][1 << i] = 1;
    cout << dfs(0, all) << endl;
  }
  return 0;
}
