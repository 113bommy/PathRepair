#include <bits/stdc++.h>
using namespace std;
int n;
int a[(int)3e5];
struct Edge {
  int v, nxt;
} edge[(int)3e5 << 1];
int fst[(int)3e5], ecnt;
void add_edge(int u, int v) {
  edge[ecnt].v = v, edge[ecnt].nxt = fst[u], fst[u] = ecnt++;
}
void init_e() { memset(fst, -1, sizeof(fst)); }
int dp[(int)3e5];
int ans[(int)3e5];
void dfs1(int u, int f) {
  for (int e = fst[u]; e != -1; e = edge[e].nxt) {
    int v = edge[e].v;
    if (v == f) continue;
    dfs1(v, u);
    dp[u] += max(0, dp[v]);
  }
  dp[u] += a[u];
}
void dfs2(int u, int f) {
  for (int e = fst[u]; e != -1; e = edge[e].nxt) {
    int v = edge[e].v;
    if (v == f) continue;
    ans[v] = dp[v] + max(0, ans[u] - max(dp[v], 0));
    dfs2(v, u);
  }
}
int main() {
  init_e();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] = a[i] ? 1 : -1;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs1(1, 0);
  ans[1] = dp[1];
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
