#include <bits/stdc++.h>
using namespace std;
template <class T>
T read1() {
  T t = 0;
  bool vis = 0;
  char k;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
int s, m, sz[100005], f[100005][20], h[100005];
long long w[100005], sum[100005];
vector<int> G[100005];
void dfs(int n, int fa) {
  sum[n] = h[n] = h[fa] + (sz[n] = 1);
  f[n][0] = fa;
  for (int i = 0; f[n][i + 1] = f[f[n][i]][i]; ++i)
    ;
  for (int i = 0; i < G[n].size(); ++i)
    if (G[n][i] ^ fa)
      dfs(G[n][i], n), sz[n] += sz[G[n][i]], sum[n] += sum[G[n][i]];
}
void dfs1(int n) {
  if (f[n][0])
    w[n] = w[f[n][0]] + sum[f[n][0]] - sum[n] -
           2ll * (sz[f[n][0]] - sz[n]) * h[f[n][0]];
  for (int i = 0; i < G[n].size(); ++i)
    if (G[n][i] ^ f[n][0]) dfs1(G[n][i]);
}
int up(int x, int n) {
  for (int i = 0; n; ++i)
    if (n >> i & 1) x = f[x][i], n ^= 1 << i;
  return x;
}
int Lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  u = up(u, h[u] - h[v]);
  if (u == v) return u;
  for (int i = 19; f[u][0] ^ f[v][0]; --i)
    if (f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}
double work(int x, int y) {
  int lca = Lca(x, y);
  if (y == lca) swap(x, y);
  if (x == lca) {
    int so = up(y, h[y] - h[x] - 1);
    double z = 1ll * sz[y] * (sz[1] - sz[so]),
           t = (sum[y] - 1ll * sz[y] * h[y]) * (sz[1] - sz[so]) +
               1ll * z * (h[y] - h[x] + 1) +
               (1ll * h[x] * (sz[1] - sz[so]) + w[so]) * sz[y];
    return t / z;
  }
  double z = 1ll * sz[x] * sz[y];
  return ((sum[x] - h[x] * sz[x]) * sz[y] + (sum[y] - h[y] * sz[y]) * sz[x] +
          (h[x] + h[y] - 2 * h[lca] + 1) * z) /
         z;
}
int main() {
  s = read1<int>();
  m = read1<int>();
  for (int i = 1; i < s; ++i) {
    int u = read1<int>(), v = read1<int>();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0), dfs1(1);
  while (m--) printf("%.8f\n", work(read1<int>(), read1<int>()));
  return 0;
}
