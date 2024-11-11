#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int MOD = 1e9 + 7;
int d, n;
int a[N], root;
vector<vector<int>> g(N);
int dp(int u, int f) {
  int ret = 1;
  for (int v : g[u]) {
    if (f == v or a[v] < a[root] or a[v] > a[root] + d or
        (a[v] == a[root] and v > root))
      continue;
    ret = 1ll * ret * (dp(v, u) + 1) % MOD;
  }
  return ret;
}
int main() {
  scanf("%d%d", &d, &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    root = i;
    ans += dp(i, -1);
  }
  printf("%d\n", ans);
}
