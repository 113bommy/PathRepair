#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dp[1 << 10][1 << 10];
int bit[1 << 10];
int con[10][10];
int maxmsk;
int dfs(int tree, int leaf) {
  int &ret = dp[tree][leaf];
  if (ret != -1) return ret;
  if (bit[leaf] < 2) return ret = 0;
  int u = -1, v;
  for (int i = 0; i < n; i++) {
    if (leaf & (1 << i)) {
      if (u == -1)
        u = i;
      else
        v = i;
    }
  }
  if (bit[tree] == 2) {
    return ret = con[u][v];
  }
  ret = 0;
  for (int v = 0; v < n; v++) {
    if (!con[u][v]) continue;
    if (!(tree & (1 << v))) continue;
    if (leaf & (1 << v)) continue;
    ret += dfs(tree ^ 1 << u, leaf ^ 1 << u);
    ret += dfs(tree ^ 1 << u, leaf ^ 1 << u ^ 1 << v);
  }
  return ret;
}
int main() {
  bit[0] = 0;
  for (int i = 1; i < 1024; i++) {
    bit[i] = bit[i & (i - 1)] + 1;
  }
  cin >> n >> m >> k;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    con[a][b] = con[b][a] = 1;
  }
  maxmsk = (1 << n) - 1;
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= maxmsk; i++) {
    if (bit[i] == k) {
      ans += dfs(maxmsk, i);
    }
  }
  cout << ans << endl;
  return 0;
}
