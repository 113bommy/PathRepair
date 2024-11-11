#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const double eps = 1e-13;
double a[maxn], b[maxn], p1[maxn], p2[maxn], z1, z2;
int n;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}
bool judge(double x, int md) {
  if (md)
    return dcmp(x * (x - z1) + z2) >= 0;
  else
    return dcmp(x * (x - z1) + z2) <= 0;
}
double BS(double l, double r, int cnt, int md) {
  if (!cnt) return l;
  double m = (l + r) / 2;
  if (judge(m, md))
    return BS(l, m, cnt - 1, md);
  else
    return BS(m, r, cnt - 1, md);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p1[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p2[i]);
  }
  for (int i = 1; i <= n; i++) {
    z1 = p1[i] + p2[i] + a[i - 1] + b[i - 1];
    z2 = p1[i] + a[i - 1] * b[i - 1];
    a[i] = BS(0, z1 / 2, 100, 0);
    b[i] = BS(z1 / 2, z1, 100, 1);
  }
  for (int i = 1; i <= n; i++) {
    if (dcmp(a[i] - a[i - 1]))
      printf("%.13lf ", a[i] - a[i - 1]);
    else
      printf("0 ");
  }
  printf("\n");
  for (int i = 1; i <= n; i++) {
    if (dcmp(b[i] - b[i - 1]))
      printf("%.13lf ", b[i] - b[i - 1]);
    else
      printf("0 ");
  }
  printf("\n");
  return 0;
}
