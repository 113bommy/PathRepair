#include <bits/stdc++.h>
using namespace std;
double a[1100];
int main() {
  int n, l;
  while (~scanf("%d %d", &n, &l)) {
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
    sort(a, a + n);
    double d = -1;
    for (int i = 1; i < n; i++) d = max(a[i] - a[i - 1], d);
    d = max(d / 2.0, a[0]);
    d = max(d, l - a[n - 1]);
    printf("%.10lf\n", d);
  }
  return 0;
}
