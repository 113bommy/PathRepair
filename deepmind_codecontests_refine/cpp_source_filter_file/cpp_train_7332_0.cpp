#include <bits/stdc++.h>
using namespace std;
struct P {
  double d;
  int r;
} a[1005];
bool cmp(P a, P b) { return a.d < b.d; }
int main() {
  int n, s, z, dd, flag = -1, ans = 0;
  double x, y;
  scanf("%d%d", &n, &s);
  dd = 1000000 - s;
  if (dd > 0) {
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%d", &x, &y, &z);
      a[i].d = sqrt(x * x + y * y);
      a[i].r = z;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
      ans = ans + a[i].r;
      if (ans >= dd) {
        flag = i;
        break;
      }
    }
    if (flag != -1)
      printf("%.7lf\n", a[flag].d);
    else
      printf("0\n");
  } else
    printf("0\n");
  return 0;
}
