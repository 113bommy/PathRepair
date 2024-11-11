#include <bits/stdc++.h>
using namespace std;
int n, m, k, h[300005], tot;
map<pair<int, int>, int> c;
struct edge {
  int to, nxt, val;
} e[300005 << 1];
void add(int x, int y, int z) {
  e[++tot].nxt = h[x];
  h[x] = tot;
  e[tot].to = y;
  e[tot].val = z;
}
priority_queue<pair<long long, int> > q;
vector<int> a[300005];
long long d[300005];
int v[300005], fa[300005];
void dij() {
  memset(d, 0x3f, sizeof(d));
  d[1] = 0;
  q.push(make_pair(0, 1));
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    v[x] = 1;
    for (int i = h[x]; i; i = e[i].nxt)
      if (d[x] + e[i].val < d[e[i].to]) {
        d[e[i].to] = d[x] + e[i].val;
        fa[e[i].to] = x;
        q.push(make_pair(-d[e[i].to], e[i].to));
      }
    while (!q.empty() && v[q.top().second]) q.pop();
  }
  for (int i = 2; i <= n; i++) a[fa[i]].push_back(i);
}
void dfs(int x) {
  if (k && x != 1) k--, printf("%d ", c[make_pair(fa[x], x)]);
  if (!k) return;
  for (int i = 0; i < (int)a[x].size(); i++) dfs(a[x][i]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  k = min(k, n - 1);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
    c[make_pair(x, y)] = c[make_pair(y, x)] = i;
  }
  dij();
  printf("%d\n", k);
  dfs(1);
  return 0;
}
