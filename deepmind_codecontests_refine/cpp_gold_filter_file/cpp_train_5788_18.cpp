#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  int x = 0, f = 1;
  char a = getchar();
  while (a < '0' || a > '9') {
    if (a == '-') f = -1;
    a = getchar();
  }
  while (a >= '0' && a <= '9') x = x * 10 + a - '0', a = getchar();
  return x * f;
}
int n, k, cnt = 1, head[200005], d[200005];
long long ans, dp[200005][10], g[200005][10];
struct edges {
  int to, next;
} e[2 * 200005];
inline void insert() {
  int u = read(), v = read();
  d[u]++;
  d[v]++;
  e[++cnt] = (edges){v, head[u]};
  head[u] = cnt;
  e[++cnt] = (edges){u, head[v]};
  head[v] = cnt;
}
void dfs(int x, int fa) {
  g[x][0] = 1;
  long long delta = 0;
  for (int i = head[x]; i; i = e[i].next) {
    if (fa == e[i].to) continue;
    dfs(e[i].to, x);
    for (int a = 0; a < k; a++)
      for (int b = 0; b < k; b++) {
        if (a + b + 1 <= k)
          delta +=
              (dp[x][a] + g[x][a]) * g[e[i].to][b] + dp[e[i].to][b] * g[x][a];
        else
          delta += (dp[x][a] + 2 * g[x][a]) * g[e[i].to][b] +
                   dp[e[i].to][b] * g[x][a];
      }
    for (int a = 0; a < k; a++) g[x][(a + 1) % k] += g[e[i].to][a];
    for (int a = 0; a < k - 1; a++) dp[x][(a + 1) % k] += dp[e[i].to][a];
    dp[x][0] += dp[e[i].to][k - 1] + g[e[i].to][k - 1];
  }
  ans += delta;
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i < n; i++) insert();
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
