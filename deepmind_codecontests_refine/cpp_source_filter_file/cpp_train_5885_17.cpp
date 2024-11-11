#include <bits/stdc++.h>
int main(void) {
  double l1, l2, l3;
  double res;
  while (scanf("%lf %lf %lf", &l1, &l2, &l3) != EOF) {
    res = ((sqrt(2) / 12) * (l1 * l1 * l1)) + ((sqrt(2) / 6) * (l2 * l2 * l2)) +
          (1.0 / 3) * (5.0 / 2) * l3 * sin(54 * 1.0 / 180 * acos(-1.0)) *
              (l3 * 1.0 / 2) / sin(36 * 1.0 / 180 * acos(-1.0)) *
              sqrt((sqrt(3) / 2) * l3 * 1.0 * (sqrt(3) / 2) * l3 * 1.0 -
                   sin(54 * 1.0 / 180 * acos(-1.0)) * (l3 * 1.0 / 2) /
                       sin(36 * 1.0 / 180 * acos(-1.0)) *
                       sin(54 * 1.0 / 180 * acos(-1.0)) * (l3 * 1.0 / 2) /
                       sin(36 * 1.0 / 180 * acos(-1.0)));
    printf("%f\n", res);
  }
  return 0;
}
