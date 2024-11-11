#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node {
  int u, v, w;
} e[N];
int n, m, fa[N], a[N];
long long ans, sz[N], res[N];
bool cmp(node a, node b) { return a.w < b.w; }
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  int rx = find(x), ry = find(y);
  if (rx != ry) {
    fa[rx] = ry;
    ans += sz[rx] * sz[ry];
    sz[ry] += sz[rx];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  sort(e + 1, e + n, cmp);
  for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1LL;
  for (int i = 1; i < n; i++) {
    int rx = find(e[i].u), ry = find(e[i].v);
    if (rx != ry) {
      merge(e[i].u, e[i].v);
      res[i] = ans;
    }
    a[i] = e[i].w;
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    printf("%d ", res[upper_bound(a + 1, a + n, x) - a - 1]);
  }
  return 0;
}
