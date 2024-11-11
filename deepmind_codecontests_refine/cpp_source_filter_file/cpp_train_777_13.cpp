#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const double INF = 1e18;
int n, a[N];
int fi[N], nxt[N << 1], to[N << 1], w[N << 1], tot;
void add(int x, int y, int z) {
  nxt[++tot] = fi[x], fi[x] = tot, to[tot] = y, w[tot] = z;
}
bool ban[N];
int sz[N], rt, Siz;
void pre_dfs(int u, int f) {
  sz[u] = 1;
  for (int i = fi[u]; i; i = nxt[i]) {
    int v = to[i];
    if (ban[v] || v == f) continue;
    pre_dfs(v, u);
    sz[u] += sz[v];
  }
}
void getrt(int u, int f) {
  int mx = sz[0] - sz[u];
  for (int i = fi[u]; i; i = nxt[i]) {
    int v = to[i];
    if (ban[v] || v == f) continue;
    getrt(v, u);
    mx = max(mx, sz[v]);
  }
  if (mx < Siz) Siz = mx, rt = u;
}
double S[N], ans = INF, now;
int nd;
void calc(int u, int f, double d) {
  now += d * sqrt(d) * a[u];
  for (int i = fi[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == f) continue;
    calc(v, u, d + w[i]);
  }
}
void dfs(int r, int u, int f, double d) {
  S[r] += 1.5 * a[u] * sqrt(d);
  for (int i = fi[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == f) continue;
    dfs(r, v, u, d + w[i]);
  }
}
void work(int u) {
  rt = 0;
  pre_dfs(u, 0);
  Siz = sz[0] = sz[u];
  getrt(u, 0);
  u = rt;
  double Sm = 0;
  ban[u] = true;
  for (int i = fi[u]; i; i = nxt[i]) {
    int v = to[i];
    if (ban[v]) continue;
    S[v] = 0, dfs(v, v, u, w[i]);
    Sm += S[v];
  }
  now = 0;
  calc(u, 0, 0);
  if (now < ans) ans = now, nd = u;
  for (int i = fi[u]; i; i = nxt[i]) {
    int v = to[i];
    if (ban[v]) continue;
    if (Sm - S[v] * 2 < 0) work(v);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, x, y, z; i < n; i++)
    scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
  work(1);
  printf("%d %.8lf", nd, ans);
  return 0;
}
