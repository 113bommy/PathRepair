#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
const int mod = 1000000007;
int n, m, K, X;
int cnt, head[N];
struct Edge {
  int nxt, to;
} e[N << 1];
int dp[N][13][3], g[13][3];
void add(int u, int v) { e[++cnt] = (Edge){head[u], v}, head[u] = cnt; }
void dfs(int x, int fa) {
  dp[x][0][0] = K - 1, dp[x][0][1] = m - K;
  if (X) dp[x][1][2] = 1;
  for (int i = head[x]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (to == fa) continue;
    dfs(to, x);
    for (int j = X; j >= 0; j--) g[j][0] = g[j][1] = g[j][2] = 0;
    for (int j = 0; j <= X; j++)
      for (int k = 0; j + k <= X; k++) {
        g[j + k][0] =
            (g[j + k][0] +
             1ll * ((dp[to][k][0] + dp[to][k][1]) % mod + dp[to][k][2]) % mod *
                 dp[x][j][0] % mod) %
            mod;
        g[j + k][1] = (g[j + k][1] + 1ll * (dp[to][k][0] + dp[to][k][1]) % mod *
                                         dp[x][j][1] % mod) %
                      mod;
        g[j + k][2] =
            (g[j + k][2] = 1ll * dp[to][k][0] * dp[x][j][2] % mod) % mod;
      }
    for (int j = X; j >= 0; j--)
      dp[x][j][0] = g[j][0], dp[x][j][1] = g[j][1], dp[x][j][2] = g[j][2];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }
  scanf("%d%d", &K, &X);
  dfs(1, 0);
  int ans = 0;
  for (int j = 0; j <= X; j++)
    ans = (ans + ((dp[1][j][0] + dp[1][j][1]) % mod + dp[1][j][2]) % mod) % mod;
  printf("%d", ans);
  return 0;
}
