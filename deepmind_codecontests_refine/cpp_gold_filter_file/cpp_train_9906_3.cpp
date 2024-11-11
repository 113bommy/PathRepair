#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 10;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n;
int to[NR << 1], val[NR << 1], nxt[NR << 1], head[NR], tot = 1;
void add(int x, int y, int z) {
  to[tot] = y, val[tot] = z, nxt[tot] = head[x], head[x] = tot++;
}
long long dp[NR][2][2], ans;
int s[NR], t[NR], tt;
void dfs(int x, int fa_) {
  int Ans = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa_) continue;
    dfs(y, x);
    int v = val[i];
    if (!v)
      ans += (dp[y][0][0] + 1) * (dp[x][0][1] + dp[x][1][1] + dp[x][0][0]);
    else
      ans += (dp[y][1][0] + dp[y][0][0] + 1 + dp[y][1][1]) * dp[x][1][1];
    if (!v)
      dp[x][0][0] += dp[y][0][0] + 1, dp[x][0][1] += dp[y][0][1] + dp[y][1][1];
    else
      dp[x][1][1] += dp[y][1][1] + 1, dp[x][1][0] += dp[y][0][0] + dp[y][1][0];
  }
  tt = 0;
  memset(dp[x], 0, sizeof(dp[x]));
  for (int i = head[x]; i; i = nxt[i])
    if (to[i] != fa_) t[++tt] = to[i], s[tt] = val[i];
  for (int i = tt; i >= 1; i--) {
    int y = t[i], v = s[i];
    if (!v)
      ans += (dp[y][0][0] + 1) * (dp[x][0][1] + dp[x][1][1] + dp[x][0][0]);
    else
      ans += (dp[y][1][0] + dp[y][0][0] + 1 + dp[y][1][1]) * dp[x][1][1];
    if (!v)
      dp[x][0][0] += dp[y][0][0] + 1, dp[x][0][1] += dp[y][0][1] + dp[y][1][1];
    else
      dp[x][1][1] += dp[y][1][1] + 1, dp[x][1][0] += dp[y][0][0] + dp[y][1][0];
  }
  ans += dp[x][0][1] + dp[x][1][0] + dp[x][1][1] * 2 + dp[x][0][0] * 2;
}
int main() {
  n = read();
  for (int i = 1, x, y, z; i < n; i++)
    x = read(), y = read(), z = read(), add(x, y, z), add(y, x, z);
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
