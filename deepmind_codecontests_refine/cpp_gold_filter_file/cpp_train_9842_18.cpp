#include <bits/stdc++.h>
int main() {
  double d, h, v, e;
  scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
  if (v / (d * d * 3.1415926 / 4) > e)
    printf("YES\n%f", h / (v / (d * d * 3.1415926 / 4) - e));
  else
    printf("NO");
}
