#include <bits/stdc++.h>
using namespace std;
struct x {
  double a;
  double b, c;
} x[25];
int cmp(struct x m, struct x n) { return m.c < n.c; }
int main() {
  int n, a[25], s = 0;
  double v, b[25], ans = 0;
  double minn = 1e9;
  scanf("%d%lf", &n, &v);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &x[i].a);
    s += x[i].a;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lf", &x[i].b);
    x[i].c = x[i].b / x[i].a;
  }
  sort(x, x + n, cmp);
  for (int i = 0; i < n; i++) {
    ans += x[0].c * x[i].a;
  }
  if (ans < v)
    printf("%.1lf\n", ans);
  else
    printf("%.1lf\n", v);
  return 0;
}
