#include <bits/stdc++.h>
using namespace std;
int n, a[300010];
struct Edge {
  int to, next;
} e[300010 * 2];
int c1, head[300010];
inline void add_edge(int u, int v) {
  e[c1].to = v;
  e[c1].next = head[u];
  head[u] = c1++;
}
long long f[300010], ans = -100000000000000000ll;
void dfs(int u, int fa) {
  f[u] = a[u];
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    if (f[v] > 0) f[u] += f[v];
  }
  ans = max(ans, f[u]);
}
int k;
void Dfs(int u, int fa) {
  f[u] = a[u];
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    Dfs(v, u);
    if (f[v] > 0) f[u] += f[v];
  }
  if (f[u] == ans) {
    f[u] = 0;
    ++k;
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  dfs(1, 0);
  Dfs(1, 0);
  cout << ans * k << " " << k << endl;
  return 0;
}
