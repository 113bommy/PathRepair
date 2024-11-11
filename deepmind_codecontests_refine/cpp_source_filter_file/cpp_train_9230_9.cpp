#include <bits/stdc++.h>
using namespace std;
int n, a[1002], ind = 0;
double x, y, d[1002], vb, vs, mn = (double)1e10;
double dist(double _x) { return sqrt((x - _x) * (x - _x) + (y * y)); }
int main() {
  scanf("%d%lf%lf", &n, &vb, &vs);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  scanf("%lf%lf", &x, &y);
  for (int i = 0; i < n; i++)
    d[i] = dist(double(a[i])) / vs + (double)a[i] / vb;
  for (int i = 1; i < n; i++)
    if (d[i] < mn) mn = d[i], ind = i + 1;
  printf("%d", ind);
  return 0;
}
