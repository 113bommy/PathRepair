#include <bits/stdc++.h>
int main() {
  double s;
  int p, q;
  while (~scanf("%lf", &s)) {
    scanf("%d%d", &p, &q);
    double t = s / (p + q);
    printf("%.1lf\n", p * t);
  }
}
