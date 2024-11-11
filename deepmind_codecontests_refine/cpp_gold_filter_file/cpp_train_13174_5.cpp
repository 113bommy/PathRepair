#include <bits/stdc++.h>
using namespace std;
const int NR = 180 + 5;
const int MR = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline int read() {
  int x = 0;
  int bei = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') bei = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * bei;
}
int dis[NR][NR];
int d[NR];
int n, m;
struct Edge {
  int v, nxt;
} g[NR << 1];
int fte[NR], gsz;
void adde(int u, int v) {
  g[++gsz] = (Edge){v, fte[u]};
  fte[u] = gsz;
}
int dp[NR][NR];
int opt[NR];
void DP(int x, int fa) {
  for (int i = 1; i <= n; ++i) dp[x][i] = d[dis[x][i]];
  for (int i = fte[x]; i; i = g[i].nxt) {
    int y = g[i].v;
    if (y == fa) continue;
    DP(y, x);
    for (int j = 1; j <= n; ++j) dp[x][j] += min(dp[y][j], dp[y][opt[y]] + m);
  }
  int minn = INF;
  for (int i = 1; i <= n; ++i)
    if (dp[x][i] < minn) minn = dp[x][i], opt[x] = i;
}
int ans[NR];
void make_ans(int x, int fa, int wkj) {
  ans[x] = wkj;
  for (int i = fte[x]; i; i = g[i].nxt) {
    int y = g[i].v;
    if (y == fa) continue;
    make_ans(y, x, dp[y][wkj] < dp[y][opt[y]] + m ? wkj : opt[y]);
  }
}
int main() {
  memset(dis, 0x3f, sizeof(dis));
  n = read(), m = read();
  for (int i = 1; i < n; ++i) d[i] = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    dis[u][v] = dis[v][u] = 1;
    adde(u, v), adde(v, u);
  }
  for (int i = 1; i <= n; ++i) dis[i][i] = 0;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  DP(1, 0);
  printf("%d\n", dp[1][opt[1]] + m);
  make_ans(1, 0, opt[1]);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
