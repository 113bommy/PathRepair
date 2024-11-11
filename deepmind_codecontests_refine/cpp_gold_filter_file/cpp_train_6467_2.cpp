#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
struct EDGE {
  int next, to;
} edge[MAXN * 2];
int head[MAXN], tot;
inline void add(int u, int v) {
  edge[++tot].next = head[u];
  edge[tot].to = v;
  head[u] = tot;
}
int n, a[MAXN], k = 0;
long long dp[MAXN], ans = -1e9;
void dfs1(int u, int fa) {
  dp[u] = a[u];
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs1(v, u);
    dp[u] += max(dp[v], 0LL);
  }
  ans = max(ans, dp[u]);
}
void dfs2(int u, int fa) {
  dp[u] = a[u];
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs2(v, u);
    dp[u] += max(dp[v], 0LL);
  }
  if (dp[u] == ans) {
    dp[u] = 0;
    k++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  cout << ans * k << " " << k << endl;
  return 0;
}
