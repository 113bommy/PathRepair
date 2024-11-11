#include <bits/stdc++.h>
using namespace std;
int n;
int head[55], to[105], nxt[105], cnt, siz[55];
void add(int u, int v) {
  nxt[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
long double dp[55][55], C[55][55], g[55], tmp[55];
void dfs(int x, int fa) {
  siz[x] = 1;
  dp[x][0] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], x);
    memset(g, 0, sizeof g);
    for (int j = 0; j <= siz[to[i]]; ++j) {
      for (int k = 0; k < j; ++k) g[j] += dp[to[i]][k] * 0.5;
      g[j] += dp[to[i]][j] * (siz[to[i]] - j);
    }
    memset(tmp, 0, sizeof tmp);
    for (int j = 0; j < siz[x]; ++j) {
      for (int k = 0; k <= siz[to[i]]; ++k) {
        tmp[j + k] += dp[x][j] * g[k] * C[j + k][j] *
                      C[siz[x] + siz[to[i]] - j - k - 1][siz[to[i]] - k];
      }
    }
    for (int j = 0; j <= siz[x] + siz[to[i]]; ++j) dp[x][j] = tmp[j];
    siz[x] += siz[to[i]];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    add(u, v);
    add(v, u);
  }
  C[0][0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1.0;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  long long x = 1;
  for (long long i = 2; i < n; ++i) x = x * i;
  for (int i = 1; i <= n; ++i) {
    memset(dp, 0, sizeof dp);
    dfs(i, 0);
    double ans = dp[i][n - 1] / x;
    printf("%.10f\n", ans);
  }
  return 0;
}
