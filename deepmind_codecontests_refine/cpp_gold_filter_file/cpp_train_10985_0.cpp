#include <bits/stdc++.h>
using namespace std;
double x[100020], y[100020];
int n;
double a[100020], b[100020], c[100020], d[100020];
bool vis[100020];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &x[i]);
    x[i] += x[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &y[i]);
    y[i] += y[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    double u = x[i];
    double v = y[i];
    double d = sqrt((u + v) * (u + v) - 4 * u + 1e-12);
    a[i] = u + v + d;
    b[i] = u + v - d;
    a[i] /= 2;
    b[i] /= 2;
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  double pre = -1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= pre)
      vis[i] = 1, pre = a[i];
    else
      vis[i] = 0, pre = b[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) swap(a[i], b[i]);
  }
  for (int i = n; i >= 1; --i) {
    a[i] -= a[i - 1];
    b[i] -= b[i - 1];
  }
  for (int i = 1; i <= n; ++i) printf("%.12lf%c", a[i], i == n ? '\n' : ' ');
  for (int i = 1; i <= n; ++i) printf("%.12lf%c", b[i], i == n ? '\n' : ' ');
  return 0;
}
