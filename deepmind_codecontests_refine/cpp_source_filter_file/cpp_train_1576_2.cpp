#include <bits/stdc++.h>
double pi = acos(-1);
int n;
double R;
int main() {
  scanf("%d%lf", &n, &R);
  double l = 0, r = 10;
  for (int i = 0; i < 100; i++) {
    double mi = (l + r) / 2;
    if (asin(mi / (mi + R)) * n > pi)
      r = mi;
    else
      l = mi;
  }
  printf("%.10lf\n", l);
  return 0;
}
