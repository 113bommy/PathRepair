#include <bits/stdc++.h>
using namespace std;
int n, x0, x1, a[300000 | 1], l0[300000 | 1], r0[300000 | 1], l1[300000 | 1],
    r1[300000 | 1];
bool f[300000 | 1], g[300000 | 1];
struct node {
  int x, y, id;
  bool operator<(const node& o) const { return x == o.x ? y < o.y : x < o.x; }
} p[300000 | 1];
int main() {
  scanf("%d%d%d", &n, &x0, &x1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    p[i].id = i;
    p[i].x = (x0 + a[i] - 1) / a[i];
    p[i].y = (x1 + a[i] - 1) / a[i];
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1], g[i] = g[i - 1];
    l0[i] = l0[i - 1], l1[i] = l1[i - 1];
    r0[i] = r0[i - 1], r1[i] = r1[i - 1];
    if (!f[i] && p[i].x <= i) {
      l0[i] = p[i].x, r0[i] = i, f[i] = 1;
    }
    if (!g[i] && p[i].y <= i) {
      l1[i] = p[i].y, r1[i] = i, g[i] = 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    int u = i - p[i].x;
    if (u >= 1 && g[u]) {
      puts("Yes");
      printf("%d %d\n", p[i].x, l1[u]);
      for (int j = u + 1; j <= i; j++)
        printf("%d%c", p[j].id, j == i ? '\n' : ' ');
      for (int j = r1[u] - l1[u] + 1; j <= r1[u]; j++)
        printf("%d%c", p[j].id, j == r1[u] ? '\n' : ' ');
      return 0;
    }
    int v = i - p[i].y;
    if (v >= 1 && f[v]) {
      puts("Yes");
      printf("%d %d\n", l0[u], p[i].y);
      for (int j = r0[v] - l0[v] + 1; j <= r0[v]; j++)
        printf("%d%c", p[j].id, j == r0[v] ? '\n' : ' ');
      for (int j = v + 1; j <= i; j++)
        printf("%d%c", p[j].id, j == i ? '\n' : ' ');
      return 0;
    }
  }
  puts("No");
  return 0;
}
