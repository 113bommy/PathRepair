#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int h[1000010], e[1000010], ne[1000010], idx;
long long dp[1000010][3], f[1000010];
void add(int a, int b) {
  e[++idx] = b;
  ne[idx] = h[a];
  h[a] = idx;
}
void dfs(int u, int fa) {
  dp[u][0] = dp[u][1] = dp[u][2] = 1;
  for (int i = h[u]; i; i = ne[i]) {
    int j = e[i];
    if (j == fa) continue;
    dfs(j, u);
    dp[u][0] = dp[u][0] * (dp[j][1] + f[j]) % mod;
    dp[u][1] = dp[u][1] * (dp[j][0] + dp[j][1] + f[j]) % mod;
    dp[u][2] = dp[u][2] * f[j] % mod;
  }
  f[u] = (dp[u][0] + dp[u][1] - dp[u][2] + mod) % mod;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
    add(b, a);
  }
  dfs(1, 0);
  printf("%lld", f[1] - 1);
  return 0;
}
