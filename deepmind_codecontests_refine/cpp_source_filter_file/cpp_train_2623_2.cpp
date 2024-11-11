#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int sz[N], p[N][20];
int dep[N];
double f[N];
int n, sumin, sumout;
double sumx[N], in[N], ou[N];
struct edge {
  int v, next;
} e[N << 1];
int head[N], tot;
double ans;
void add(int u, int v) {
  e[++tot].v = v;
  e[tot].next = head[u];
  head[u] = tot;
}
void dfs(int u, int fa) {
  p[u][0] = fa;
  sz[u] = 1;
  sumx[u] = in[u];
  for (int i = 1; i <= 19; i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
  }
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
    sumx[u] += sumx[v];
    f[u] += (double)1.0 * sz[v] * sumx[v];
  }
  if (u != 1) f[u] += (double)(n - sz[u]) * (1.0 - sumx[u]);
  f[u] *= ou[u];
  ans += f[u];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &in[i], &ou[i]);
    sumin += in[i];
    sumout += ou[i];
  }
  for (int i = 1; i <= n; i++) {
    in[i] = 1.0 * in[i] / sumin;
    ou[i] = 1.0 * ou[i] / sumout;
  }
  dfs(1, 0);
  printf("%lf\n", ans);
  return 0;
}
