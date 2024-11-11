#include <bits/stdc++.h>
const int mod = 998244353;
const int N = 300005;
using LL = long long;
int n, head[N], tot, dp[N][3];
struct edge {
  int to, nxt;
} e[N << 1];
void link(int x, int y) {
  e[++tot] = (edge){y, head[x]}, head[x] = tot;
  e[++tot] = (edge){x, head[y]}, head[y] = tot;
}
void dfs(int x, int f = 0) {
  dp[x][0] = 1;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      dfs(e[i].to, x);
      int *p = dp[x], *d = dp[e[i].to];
      p[2] = (p[2] * ((LL)d[0] + d[2] + d[2]) + p[1] * ((LL)d[0] + d[1]) +
              p[0] * ((LL)d[0] + d[1])) %
             mod;
      p[1] = (p[1] * ((LL)d[0] + d[2] + d[2]) + p[0] * (LL)d[2]) % mod;
      p[0] = p[0] * ((LL)d[0] + d[2]) % mod;
    }
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 1, u, v; i < n; ++i) std::cin >> u >> v, link(u, v);
  dfs(1);
  int ans = dp[1][0] + dp[1][2] - mod;
  ans += ans >> 31 & mod;
  std::cout << ans << std::endl;
  return 0;
}
