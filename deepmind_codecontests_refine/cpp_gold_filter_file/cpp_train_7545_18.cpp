#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1005;
bool bad[maxn];
vector<int> blocked;
vector<int> g[maxn];
bool seen[maxn];
int deg[maxn];
vector<int> good;
int n, m, k;
bool can(double mid) {
  memset(bad, 0, sizeof(bad));
  memset(deg, 0, sizeof(deg));
  memset(seen, 0, sizeof(seen));
  queue<int> q;
  for (int i = 0; i < n; ++i) deg[i] = ((int)((g[i]).size()));
  for (int i = 0; i < ((int)((blocked).size())); i++) q.push(blocked[i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (seen[u]) continue;
    seen[u] = 1;
    for (int i = 0; i < ((int)((g[u]).size())); i++) {
      int v = g[u][i];
      if (bad[v]) continue;
      deg[v]--;
      if (double(deg[v] / (1.0 * ((int)((g[v]).size())))) < mid) q.push(v);
    }
  }
  good.clear();
  for (int i = 0; i < n; ++i)
    if (!seen[i]) good.push_back(i);
  return ((int)((good).size())) > 0;
}
int main() {
  int u, v;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; ++i) scanf("%d", &u), --u, blocked.push_back(u);
  for (int i = 0; i < m; ++i)
    scanf("%d %d", &u, &v), --u, --v, g[u].push_back(v), g[v].push_back(u);
  double l = 0, r = 1.0;
  double ans = 0.0;
  for (int i = 0; i < 50; ++i) {
    double mid = (l + r) / 2.0;
    if (can(mid))
      l = mid, ans = mid;
    else
      r = mid;
  }
  can(ans);
  assert(((int)((good).size())) <= n - k);
  assert(((int)((good).size())) != 0);
  printf("%d\n", ((int)((good).size())));
  for (int i = 0; i < ((int)((good).size())); i++) printf("%d ", good[i] + 1);
  return 0;
}
