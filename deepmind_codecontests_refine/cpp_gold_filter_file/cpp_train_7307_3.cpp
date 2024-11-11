#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, x, y, z, a[N], head[N], cnt;
bool vis[N];
int q[N], h, t, ans;
struct node {
  int v, nex;
} e[N * 2];
void add(int u, int v) {
  e[++cnt] = node{v, head[u]};
  head[u] = cnt;
}
void ext(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  q[++t] = u;
}
void dfs(int u, int fa, int d) {
  if (d > k) return;
  a[u] -= z;
  for (int i = head[u]; i; i = e[i].nex) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u, d + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  h = 1;
  t = 0;
  ext(1);
  while (h <= t) {
    x = q[h++];
    for (int i = head[x]; i; i = e[i].nex) {
      int v = e[i].v;
      ext(v);
    }
  }
  for (int i = n; i; i--) {
    x = q[i];
    if (a[x] <= 0) continue;
    z = a[x];
    ans += z;
    dfs(x, 0, 0);
  }
  printf("%d\n", ans);
  return 0;
}
