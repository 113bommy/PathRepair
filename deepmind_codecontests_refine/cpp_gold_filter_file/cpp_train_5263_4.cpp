#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> g[maxn];
int b[maxn];
void dfs(int u, int f) {
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == f) continue;
    dfs(v, u);
    b[u] += b[v];
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= 2 * k; i++) {
    int t;
    scanf("%d", &t);
    b[t] = 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += min(b[i], 2 * k - b[i]);
  printf("%lld\n", ans);
  return 0;
}
