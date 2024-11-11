#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int inf = 0x3f3f3f3f;
int tot, rt, a[N], dp[N][20], fa[N][20];
int to[N << 1], nxt[N << 1], head[N];
long long res;
void addEdge(int u, int v) { to[++tot] = v, nxt[tot] = head[u], head[u] = tot; }
void dfs(int u, int from = -1) {
  if (u != rt) {
    long long w = dp[u][0];
    for (int i = 1; i < 20; i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
      dp[u][i] = min(dp[u][i - 1], dp[fa[u][i - 1]][i - 1]);
      w = min(w, 1LL * (i + 1) * dp[u][i]);
    }
    res += w + a[u];
  }
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == from) continue;
    dp[v][0] = a[u], fa[v][0] = u;
    dfs(v, u);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int mn = inf;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < mn) mn = a[i], rt = i;
  }
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  memset(dp, 0x3f, sizeof(dp));
  dfs(rt);
  printf("%lld\n", res);
}
