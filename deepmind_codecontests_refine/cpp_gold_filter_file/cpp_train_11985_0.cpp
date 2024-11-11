#include <bits/stdc++.h>
using namespace std;
const int max_n = 300005;
int n, m;
struct edge {
  int u, v, next;
} G[max_n * 2];
int total;
int head[max_n];
void add_edge(int u, int v) {
  G[total].u = u;
  G[total].v = v;
  G[total].next = head[u];
  head[u] = total++;
}
vector<pair<int, int> > qry[max_n];
long long ans[max_n];
long long bit[max_n];
void add(int i, long long x) {
  for (; i <= n; i += i & -i) bit[i] += x;
}
long long sum(int i) {
  long long res = 0;
  for (; i; i -= i & -i) res += bit[i];
  return res;
}
void dfs(int u, int fa, int dep) {
  for (auto p : qry[u]) add(dep, p.second), add(dep + p.first + 1, -p.second);
  ans[u] = sum(dep);
  int v;
  for (int i = head[u]; ~i; i = G[i].next) {
    v = G[i].v;
    if (v == fa) continue;
    dfs(v, u, dep + 1);
  }
  for (auto p : qry[u]) add(dep, -p.second), add(dep + p.first + 1, p.second);
}
int main() {
  scanf("%d", &n);
  memset(head, -1, sizeof(head));
  int x, y;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  scanf("%d", &m);
  int v, d;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &v, &d, &x);
    qry[v].push_back(pair<int, int>(d, x));
  }
  dfs(1, -1, 1);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
