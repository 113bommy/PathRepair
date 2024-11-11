#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> e[maxn];
long long a[maxn];
long long node[maxn];
long long dp[maxn];
long long res;
int n;
void init() {
  memset(node, 0, sizeof(node));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= n; i++) e[i].clear();
}
int dfs(int u, int fa) {
  node[u] = a[u];
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == fa) continue;
    node[u] += dfs(v, u);
    res += node[v];
  }
  return node[u];
}
void dfs2(int u, int fa, long long sum) {
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == fa) continue;
    res = max(res, sum + node[1] - 2 * node[v]);
    dfs2(v, u, sum + node[1] - 2 * node[v]);
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    res = 0;
    dfs(1, 0);
    dfs2(1, 0, res);
    cout << res << endl;
  }
  return 0;
}
