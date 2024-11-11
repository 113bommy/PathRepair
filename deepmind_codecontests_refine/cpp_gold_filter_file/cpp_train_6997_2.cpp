#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3100;
int cnt, n;
int head[MAXN], siz[MAXN][MAXN], fa[MAXN][MAXN], nxt[2 * MAXN], to[2 * MAXN];
long long dp[MAXN][MAXN], ans;
void add(int x, int y) {
  nxt[++cnt] = head[x];
  to[cnt] = y;
  head[x] = cnt;
}
void dfs(int x, int root) {
  siz[x][root] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa[x][root]) continue;
    fa[to[i]][root] = x;
    dfs(to[i], root);
    siz[x][root] += siz[to[i]][root];
  }
}
long long dfs2(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  return dp[x][y] =
             siz[x][y] * siz[y][x] + max(dfs2(x, fa[y][x]), dfs2(fa[x][y], y));
}
int main() {
  scanf("%d", &n);
  int tu, tv;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d", &tu, &tv);
    add(tu, tv);
    add(tv, tu);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) dp[i][i] = 0;
  for (int i = 1; i <= n; i++) dfs(i, i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans = max(ans, dfs2(i, j));
  printf("%I64d\n", ans);
  return 0;
}
