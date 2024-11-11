#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 1e18;
long long mn = 0, mx = 0;
int n, tot;
int head[maxn], num[maxn];
struct nodee {
  int v, w, nxt;
} g[maxn << 1];
void add(int u, int v, int w) {
  g[tot] = {v, w, head[u]};
  head[u] = tot++;
}
void dfs(int x, int fa) {
  num[x]++;
  for (int i = head[x]; ~i; i = g[i].nxt)
    if (g[i].v != fa) {
      dfs(g[i].v, x);
      int res = num[g[i].v];
      mn += 1ll * (res % 2) * g[i].w;
      mx += 1ll * min(res, n - res) * g[i].w;
      num[x] += num[g[i].v];
    }
}
void rua() {
  scanf("%d", &n);
  n *= 2;
  tot = 0;
  mn = mx = 0;
  for (int i = 0; i <= n; i++) num[i] = 0, head[i] = -1;
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
  }
  dfs(1, 0);
  printf("%lld %lld\n", mn, mx);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) rua();
  return 0;
}
