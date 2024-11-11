#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
long long a[maxn];
double f(double x) {
  double mx, mi;
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      mx = mi = a[i] - x * i;
    else {
      mx = max(mx, a[i] - x * i);
      mi = min(mi, a[i] - x * i);
    }
  }
  mx = max(0., mx), mi = min(0., mi);
  return mx - mi;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    a[i] += a[i - 1];
  }
  double l = -1e10, r = 1e10;
  for (int i = 1; i <= 200; i++) {
    double l1 = (2 * l + r) / 3, r1 = (l + 2 * r) / 3;
    if (f(l1) < f(r1))
      r = r1;
    else
      l = l1;
  }
  printf("%.10f\n", f(l));
  return 0;
}
