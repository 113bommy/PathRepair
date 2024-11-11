#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, x, cnt[N], ne[N][10], g[15], f[15], dp[N][N][15], sd[N], tot;
char s[N];
void dfs(int x) {
  for (int i = 0; i < 10; i++)
    if (ne[x][i]) dfs(ne[x][i]);
  for (int i = 0; i <= sd[x]; i++) {
    memset(f, 0, sizeof f);
    for (int j = 0; j < 10; j++)
      if (ne[x][j]) {
        memset(g, 0x3f, sizeof g);
        int to = ne[x][j];
        for (int x = 0; x <= m; x++)
          for (int y = 0; y <= m; y++)
            g[x + y] = min(g[x + y], f[x] + dp[to][i][y]);
        for (int x = 0; x <= m; x++) f[x] = g[x];
      }
    if (i != sd[x]) {
      for (int j = 0; j <= m; j++) dp[x][i][j] = f[j] + cnt[x] * (sd[x] - i);
    } else {
      if (i == 0)
        printf("%d\n", f[m]);
      else
        for (int j = 0; j < sd[x]; j++)
          for (int k = 0; k < m; k++)
            dp[x][j][k + 1] = min(dp[x][j][k + 1], f[k]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s%d", s + 1, &x);
    int p = 0;
    for (int j = 1; s[j]; j++) {
      int t = s[j] - '0';
      if (!ne[p][t]) ne[p][t] = ++tot, sd[tot] = j;
      p = ne[p][t];
    }
    cnt[p] += x;
  }
  dfs(0);
}
