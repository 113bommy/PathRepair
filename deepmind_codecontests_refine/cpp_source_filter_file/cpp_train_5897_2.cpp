#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, len;
int d[maxn][2];
vector<int> from[maxn];
int q[maxn];
int lay[maxn], deg[maxn];
long long ans;
vector<pair<int, int> > p;
void dfs(int u, int last, int t) {
  d[u][t] = (last == 0 ? -1 : d[last][t]) + 1;
  for (auto v : from[u])
    if (v != last) dfs(v, u, t);
}
void dfs2(int u, int last, int st) {
  for (auto v : from[u])
    if (v != last && lay[v]) dfs2(v, u, st);
  ans += d[u][0];
  if (st != u) p.push_back({st, u});
}
int main() {
  int i, x, y, l, r, u, v;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    from[x].push_back(y);
    from[y].push_back(x);
  }
  dfs(1, 0, 0);
  pair<int, int> t1 = {-1, 0};
  for (i = 1; i <= n; i++) t1 = max(t1, {d[i][0], i});
  dfs(t1.second, 0, 0);
  pair<int, int> t2 = {-1, 0};
  for (i = 1; i <= n; i++) t2 = max(t2, {d[i][0], i});
  dfs(t2.second, 0, 1);
  len = t2.first;
  l = 1;
  r = 0;
  for (i = 1; i <= n; i++)
    deg[i] = from[i].size(), lay[i] = (d[i][0] + d[i][1] == len);
  for (i = 1; i <= n; i++)
    if (deg[i] == 1 && !lay[i]) q[++r] = i;
  while (l <= r) {
    u = q[l++];
    if (d[u][0] >= d[u][1])
      p.push_back({t1.second, u}), ans += d[u][0];
    else
      p.push_back({t2.second, u}), ans += d[u][1];
    for (auto v : from[u]) {
      deg[v]--;
      if (deg[v] == 1 && !lay[v]) q[++r] = i;
    }
  }
  dfs2(t1.second, 0, t1.second);
  printf("%I64d\n", ans);
  for (auto t : p) printf("%d %d %d\n", t.first, t.second, t.second);
}
