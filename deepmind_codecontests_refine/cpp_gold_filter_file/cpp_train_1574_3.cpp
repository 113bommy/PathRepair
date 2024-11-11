#include <bits/stdc++.h>
using namespace std;
struct node {
  int b, l;
  node() {}
  node(int _b, int _l) {
    b = _b;
    l = _l;
  }
} a[1111];
double ans = 0;
int n, m, c;
void dfs(int now, int rem) {
  if (!rem || now == n) {
    int h = 0, i, j, k = n / 2 + 1;
    double t = 0;
    for (i = 0; i < (1 << n); i++) {
      double x = 1;
      for (j = 0; j < n; j++) {
        if (i & (1 << j)) {
          x *= a[j].l / 10.0;
        } else {
          x *= (10 - a[j].l) / 10.0;
        }
      }
      if (__builtin_popcount(i) >= k) {
        t += x;
        continue;
      }
      int bb = 0;
      for (j = 0; j < n; j++) {
        if (i & (1 << j)) {
          continue;
        }
        bb += a[j].b;
      }
      t += x * (c * 1.0 / (c * 1.0 + bb * 1.0));
    }
    ans = max(ans, t);
  }
  if (now == n) return;
  int i;
  for (i = 0; i <= rem; i++) {
    int aft = a[now].l + i;
    if (aft > 10) continue;
    int bef = a[now].l;
    a[now].l = aft;
    dfs(now + 1, rem - i);
    a[now].l = bef;
  }
}
int main() {
  int i, j, k;
  scanf("%d%d%d", &n, &m, &c);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a[i].b, &a[i].l);
    a[i].l /= 10;
  }
  dfs(0, m);
  printf("%.14lf\n", ans);
  return 0;
}
