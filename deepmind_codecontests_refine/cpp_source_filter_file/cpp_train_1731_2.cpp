#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, m, fa[N], tag[N], ans;
struct node {
  int x, y, v;
  friend bool operator<(node a, node b) { return a.v > b.v; }
} a[N];
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int fx = find(a[i].x), fy = find(a[i].y);
    if (fx != fy && (!tag[fx] || !tag[fy])) {
      tag[fx] |= tag[fy];
      fa[fy] = fx;
      ans += a[i].v;
    } else if (!tag[fx]) {
      tag[fx] = 1;
      ans += a[i].v;
    }
  }
  printf("%d\n", ans);
}
