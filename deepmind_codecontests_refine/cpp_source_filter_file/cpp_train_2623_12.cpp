#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;
const int MAXN = 1e5 + 5;
int n, len;
long long res, suma, sumb;
long long a[MAXN], b[MAXN];
int head[MAXN], size[MAXN];
struct Edge {
  int to, next;
} e[MAXN << 1];
void add(int u, int v) {
  e[++len] = (Edge){v, head[u]};
  head[u] = len;
}
void dfs(int u, int fa) {
  size[u] = 1;
  for (int i = head[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    size[u] += size[v];
    a[u] += a[v];
    res += a[v] * size[v] * b[u];
  }
  res += b[u] * (n - size[u]) * (suma - a[u]);
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i], &b[i]);
    suma += a[i];
    sumb += b[i];
  }
  dfs(1, 0);
  long double ans = 1.0 * res / suma / sumb;
  printf("%.10Lf\n", ans);
  return 0;
}
