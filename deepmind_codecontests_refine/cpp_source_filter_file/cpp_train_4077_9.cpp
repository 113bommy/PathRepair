#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int n, m, dp[N], cnt[N], ok[15][15][N];
int fa[N], a[N][2], lst[15][15][N];
int v[N], nxt[N], head[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &v[i], &v[i + m]);
    nxt[i] = head[v[i + m]], head[v[i + m]] = i;
    nxt[i + m] = head[v[i]], head[v[i]] = i + m;
    ok[v[i]][v[i + m]][0] = 1, lst[v[i]][v[i + m]][0] = v[i];
    ok[v[i + m]][v[i]][0] = 1, lst[v[i + m]][v[i]][0] = v[i + m];
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int mk = 0; mk < (1 << n); mk++) {
    for (int i = 1; i <= n; i++) {
      if ((mk & (1 << i - 1))) cnt[mk]++;
      if ((mk & (1 << i - 1))) continue;
      for (int j = 1; j <= n; j++) {
        if ((mk & (1 << j - 1))) continue;
        if (i == j || !ok[i][j][mk]) continue;
        for (int k = head[j]; k > 0; k = nxt[k]) {
          if ((mk & (1 << v[k] - 1)) || i == v[k] && mk == 0) continue;
          int t = mk | (1 << j - 1);
          ok[i][v[k]][t] = 1, lst[i][v[k]][t] = j;
        }
      }
    }
  }
  memset(dp, 0x3f, sizeof(dp)), dp[1] = 0;
  for (int mk = 1; mk < (1 << n); mk++) {
    for (int s = mk; s > 0; s = (s - 1) & s) {
      int u = mk ^ s, w = cnt[s] + 1;
      if (dp[u] + w >= dp[mk]) continue;
      for (int i = 1; i <= n; i++) {
        if (!(u & (1 << i - 1))) continue;
        int jd = 0;
        for (int j = 1; j <= n; j++) {
          if (!(u & (1 << j - 1))) continue;
          if (!ok[i][j][s]) continue;
          dp[mk] = dp[u] + w, jd = 1;
          fa[mk] = u, a[mk][0] = i, a[mk][1] = j;
          break;
        }
        if (jd) break;
      }
    }
  }
  if (dp[(1 << n) - 1] == 0x3f3f3f3f) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", dp[(1 << n) - 1]);
  for (int i = (1 << n) - 1; i > 1; i = fa[i]) {
    int x = a[i][0], y = a[i][1];
    for (int j = i ^ fa[i]; j > 0; j -= (1 << y - 1)) {
      printf("%d %d\n", y, lst[x][y][j]);
      y = lst[x][y][j];
    }
    printf("%d %d\n", x, y);
  }
}
