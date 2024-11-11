#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int head[N], tot, to[M], nxt[M];
void add_edge(int x, int y) {
  nxt[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
}
int siz[N];
double in[N], out[N];
void dfs(int u, int fa) {
  siz[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) continue;
    dfs(v, u);
    siz[u] += siz[v];
    in[u] += in[v];
  }
}
double ans = 0;
int n;
void dp(int u, int fa) {
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == fa) {
      ans += (double)(n - siz[u]) * (1 - in[u]) * out[u];
      continue;
    }
    dp(v, u);
    ans += (double)in[v] * siz[v] * out[u];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  int sumin = 0, sumout = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &in[i], &out[i]);
    sumin += in[i];
    sumout += out[i];
  }
  for (int i = 1; i <= n; i++) in[i] /= sumin, out[i] /= sumout;
  dfs(1, 0);
  dp(1, 0);
  printf("%.8lf\n", ans);
  return 0;
}
