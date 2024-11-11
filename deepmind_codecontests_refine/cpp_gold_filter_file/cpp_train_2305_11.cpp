#include <bits/stdc++.h>
const int N = 300005, W = 19, mu = 998244353;
std::vector<int> a[N];
int reduce(int &x) { x += x >> 31 & mu; }
int dfn[N], id, s[N << 1], deep[N], to[N << 1], f[N][W + 1], c[N], fa[N], edge,
    Next[N << 1], last[N], col, n, k, x, y, lca, dp[N][2], cnt;
void add(int x, int y) {
  to[++edge] = y;
  s[edge] = x;
  Next[edge] = last[x];
  last[x] = edge;
}
void dfs(int x, int y) {
  dfn[x] = ++id;
  fa[x] = y, f[x][0] = y;
  for (int i = last[x]; i; i = Next[i])
    if (to[i] != y) deep[to[i]] = deep[x] + 1, dfs(to[i], x);
}
bool modify(int x, int y) {
  if (c[x]) x = fa[x];
  for (; deep[x] >= deep[y]; x = fa[x]) {
    if (c[x]) return (c[x] != col);
    c[x] = col;
  }
  return 0;
}
int solve(int x, int y) {
  if (deep[x] < deep[y]) std::swap(x, y);
  for (int i = W; i >= 0; i--)
    if (deep[f[x][i]] >= deep[y]) {
      if (modify(x, f[x][i])) return 0;
      x = f[x][i];
    }
  if (x == y) return x;
  for (int i = W; i >= 0; i--)
    if (f[x][i] != f[y][i]) {
      if (modify(x, f[x][i]) || modify(y, f[y][i])) return 0;
      x = f[x][i], y = f[y][i];
    }
  if (c[fa[x]] && c[fa[x]] != col) return 0;
  c[fa[x]] = col;
  return fa[x];
}
void Dp(int x, int y) {
  int cnt = 0;
  if (x <= k) dp[x][1] = 1;
  if (x > k) dp[x][0] = 1;
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == y) continue;
    Dp(u, x);
    cnt++;
    if (x <= k)
      dp[x][1] = 1ll * dp[x][1] * (dp[u][0] + dp[u][1]) % mu;
    else {
      dp[x][1] = (1ll * dp[x][1] * (dp[u][1] + dp[u][0]) % mu +
                  1ll * dp[x][0] * dp[u][1]) %
                 mu;
      dp[x][0] = dp[x][0] * 1ll * (dp[u][0] + dp[u][1]) % mu;
    }
  }
  if (cnt == 0) dp[x][x > k] = 0;
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    a[c[i]].push_back(i);
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  deep[1] = 1;
  dfs(1, 0);
  for (int i = 1; i <= W; i++)
    for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  for (col = 1; col <= k; col++) {
    std::sort(a[col].begin(), a[col].end(), cmp);
    lca = a[col][0];
    for (int j = 1; j < a[col].size(); j++) {
      lca = solve(lca, a[col][j]);
      if (!lca) {
        puts("0");
        return 0;
      }
    }
  }
  memset(last, 0, sizeof(last));
  cnt = k, edge = 0;
  for (int i = 1; i <= n; i++)
    if (!c[i]) c[i] = ++cnt;
  for (int i = 1; i <= (n - 1) * 2; i += 2) {
    int c1 = c[s[i]], c2 = c[to[i]];
    if (c1 != c2) add(c1, c2), add(c2, c1);
  }
  Dp(1, 0);
  printf("%d\n", dp[1][1]);
}
