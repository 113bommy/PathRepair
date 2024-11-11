#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7, inf = 1e9 + 7;
const long long linf = (long long)1e18 + 7;
const long double eps = 1e-15, pi = 3.141592;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m, k, cnt;
int b[N], w[N], dp[N];
bool was[N];
vector<int> comp[N], g[N];
inline void Dfs(int v) {
  was[v] = 1;
  comp[cnt].push_back(v);
  for (auto i : g[v])
    if (!was[i]) Dfs(i);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y), g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!was[i]) ++cnt, Dfs(i);
  dp[0] = 1;
  for (int i = 1; i <= cnt; i++) {
    for (int j = k; j >= 0; j--) {
      if (dp[j]) {
        int beauty = 0, weight = 0;
        for (auto it : comp[i]) {
          if (j + w[it] <= k) dp[j + w[it]] = max(dp[j + w[it]], dp[j] + b[it]);
          beauty += b[it], weight += w[it];
        }
        if (j + weight <= k)
          dp[j + weight] = max(dp[j + weight], dp[j] + beauty);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= k; i++) res = max(res, dp[i]);
  cout << res - 1;
  exit(0);
}
