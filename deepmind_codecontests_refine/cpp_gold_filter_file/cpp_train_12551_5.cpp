#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, mod = 1e9 + 7;
int n, k, dp[maxn][maxn], f[maxn];
int head[maxn], cnt;
struct edge {
  int to, next;
} e[maxn << 1];
void adde(int u, int v) {
  e[++cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
void dfs(int u, int fa) {
  dp[u][0] = dp[u][k + 1] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    memset(f, 0, sizeof(f));
    for (int x = 0; x <= k * 2; ++x)
      for (int y = 0; y <= k * 2; ++y)
        if (x + y <= k * 2)
          (f[min(x, y + 1)] += 1ll * dp[u][x] * dp[v][y] % mod) %= mod;
        else
          (f[max(x, y + 1)] += 1ll * dp[u][x] * dp[v][y] % mod) %= mod;
    memcpy(dp[u], f, sizeof(f));
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, u, v; i < n; i++)
    scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
  dfs(1, 0);
  long long ans = 0;
  for (int i = 0; i <= k; ++i) ans = (ans + dp[1][i]) % mod;
  printf("%lld\n", ans);
  return 0;
}
