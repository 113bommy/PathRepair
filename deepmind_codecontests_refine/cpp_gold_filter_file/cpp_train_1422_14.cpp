#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
int n, m, x[200010], t[200010];
long double now = 0, sum = 0;
struct node {
  int x, t;
} a[200010];
const bool cmp(const node &x, const node &y) { return x.t < y.t; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i].x);
    sum += a[i].x;
  }
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i].t);
    a[i].t -= m;
  }
  for (int i = (1); i <= (n); i++) now += (long double)a[i].x * a[i].t;
  if (fabs(now) < eps) {
    printf("%.15lf\n", (double)sum);
    exit(0);
  }
  sort(a + 1, a + 1 + n, cmp);
  if (now > 0) {
    for (int i = (n); i >= (1); i--) {
      if ((long double)a[i].x * a[i].t >= now) {
        sum -= now / a[i].t;
        break;
      } else {
        sum -= a[i].x;
        now -= (long double)a[i].x * a[i].t;
      }
    }
  } else {
    for (int i = (1); i <= (n); i++) {
      if ((long double)a[i].x * a[i].t <= now) {
        sum -= now / a[i].t;
        break;
      } else {
        sum -= a[i].x;
        now -= (long double)a[i].x * a[i].t;
      }
    }
  }
  printf("%.15lf\n", (double)sum);
  return 0;
}
