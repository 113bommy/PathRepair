#include <bits/stdc++.h>
const long long mod = 9898244353;
long long f[300005][3];
std::vector<int> g[300005];
int vis[300005];
void dp(int u) {
  vis[u] = 1;
  int count = 0;
  f[u][0] = f[u][1] = f[u][2] = 1;
  long long minus = 1;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (!vis[v]) {
      dp(v);
      count++;
      long long sum = (f[v][0] + f[v][1] + f[v][2]) % mod;
      minus = minus * sum % mod;
      f[u][0] = f[u][0] * sum % mod;
      long long op1 = (sum + f[v][0]) % mod;
      f[u][1] = (sum + op1) % mod * f[u][1] % mod;
      long long op2 = (f[v][0] + f[v][1]) % mod;
      f[u][2] = (sum + op2) % mod * f[u][2] % mod;
    }
  }
  if (count == 0)
    f[u][1] = f[u][2] = 0;
  else {
    f[u][1] -= minus;
    if (f[u][1] < 0) f[u][1] += mod;
    f[u][2] -= minus;
    if (f[u][2] < 0) f[u][2] += mod;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dp(1);
  long long ans = (f[1][0] + f[1][1] + f[1][2]) % mod;
  ans -= 1;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}
