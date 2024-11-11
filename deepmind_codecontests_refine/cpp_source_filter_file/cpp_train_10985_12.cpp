#include <bits/stdc++.h>
using namespace std;
double a[100100];
double b[100100];
double sa;
double sb;
double ma[100100];
double mb[100100];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &ma[i]);
  for (int i = 1; i <= n; i++) scanf("%lf", &mb[i]);
  double c = ma[1];
  double d = mb[1];
  a[1] = ((d + c) - sqrt((d + c) * (d + c) - 4.0 * c)) / (2.0);
  b[1] = d + c - a[1];
  sa = a[1], sb = b[1];
  for (int i = 2; i <= n; i++) {
    c = ma[i];
    d = mb[i];
    double y = c + d;
    a[i] =
        ((-(sa - y - sb) +
          sqrt(max((sa - y - sb) * (sa - y - sb) - 4.0 * (c - sa * y), 0.0))) /
         2.0);
    b[i] = y - a[i];
    sa += a[i];
    sb += b[i];
  }
  for (int i = 1; i <= n; i++) printf("%.9f ", a[i]);
  printf("\n");
  for (int i = 1; i <= n; i++) printf("%.9f ", b[i]);
}
