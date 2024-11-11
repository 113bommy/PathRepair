#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e5 + 1;
int x[N], y[N], vis[N], h[N], n, m, mx;
vector<int> g[N];
void dfs(int v) {
  vis[v] = true;
  int x;
  for (int i = 0; i < g[v].size(); ++i) {
    x = g[v][i];
    if (!vis[x]) dfs(x);
    h[v] = max(h[v], h[x] + 1);
  }
  mx = max(mx, h[v]);
}
bool check(int idx) {
  mx = 0;
  memset(vis, false, sizeof(vis));
  memset(h, 0, sizeof(h));
  int i;
  for (i = 1; i <= n; ++i) g[i].clear();
  for (i = 0; i <= idx; ++i) g[x[i]].push_back(y[i]);
  for (i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i);
  return (mx == n - 1 ? 1 : 0);
}
int main() {
  int i, lo, hi, mid;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
  }
  lo = 0, hi = m - 1;
  while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    (check(mid) ? hi = mid : lo = mid + 1);
  }
  if (check(lo))
    printf("%d\n", lo + 1);
  else
    printf("-1\n");
  return 0;
}
