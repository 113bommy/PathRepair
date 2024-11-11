#include <bits/stdc++.h>
int main() {
  double d, l, v1, v2;
  scanf("%lf%lf%lf%lf", &d, &l, &v1, &v2);
  printf("%.20lf", (l - d) / (v1 + v2));
}
