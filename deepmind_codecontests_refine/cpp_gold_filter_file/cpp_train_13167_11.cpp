#include <bits/stdc++.h>
using namespace std;
int n, m, u, r[300010];
long long d[300010], use[300010];
vector<pair<int, int> > g[300010];
vector<int> a[300010];
bool ds[300010];
void IJK(int u) {
  priority_queue<pair<long long, int> > q;
  memset(d, 60, sizeof(d));
  pair<long long, int> p = make_pair(d[u] = 0, u);
  q.push(p);
  while (!q.empty()) {
    pair<long long, int> p = q.top();
    q.pop();
    u = p.second;
    if (d[u] < -p.first) continue;
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].first;
      long long l = g[u][i].second;
      if (d[v] < d[u] + l || (d[v] == d[u] + l && l >= use[v])) continue;
      use[v] = l;
      d[v] = d[u] + g[u][i].second;
      r[v] = a[u][i];
      q.push(make_pair(-d[v], v));
    }
  }
}
void take() {
  long long total = 0;
  for (int i = 1; i <= n; ++i) total += use[i];
  printf("%I64d\n", total);
  for (int i = 1; i <= n; ++i)
    if (i != u) ds[r[i]] = 1;
  for (int i = 1; i <= m; ++i)
    if (ds[i]) printf("%d ", i);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y, l; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &l);
    g[x].push_back(make_pair(y, l));
    g[y].push_back(make_pair(x, l));
    a[x].push_back(i);
    a[y].push_back(i);
  }
  scanf("%d", &u);
  IJK(u);
  take();
}
