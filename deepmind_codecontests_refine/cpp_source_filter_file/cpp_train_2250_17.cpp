#include <bits/stdc++.h>
using namespace std;
int n, b[100005];
struct node {
  int d;
  int r;
  int post;
} a[10005];
bool cmp(const node x, const node y) { return x.d < y.d; }
int finder(int x) {
  int l = -1, r = n;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (a[m].d <= x) {
      l = m;
    } else
      r = m;
  }
  return r;
}
int main() {
  int x, y, m, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].d, &a[i].r);
    a[i].post = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  memset(b, -1, sizeof(b));
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    int now = finder(x);
    for (int j = now - 1; j <= now + 1; j++) {
      if (j < 1 || j > n) continue;
      int o = (x - a[j].d) * (x - a[j].d) + y * y;
      int oo = a[j].r * a[j].r;
      if (o <= oo) {
        if (b[a[j].post] == -1) {
          b[a[j].post] = i;
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (i != n)
      printf("%d ", b[i]);
    else
      printf("%d\n", b[i]);
  }
  return 0;
}
