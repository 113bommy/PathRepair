#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n, a[6005];
vector<int> g[6005];
int f[6005];
int res = 0;
void dfs(int v, int pr) {
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == pr) continue;
    int mx = lower_bound(f, f + n + 1, a[to]) - f;
    res = max(res, mx);
    int prv = f[mx];
    f[mx] = min(f[mx], a[mx]);
    dfs(to, v);
    f[mx] = prv;
  }
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    f[i] = mod;
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    f[1] = a[i];
    dfs(i, 0);
  }
  printf("%d\n", res);
  return 0;
}
