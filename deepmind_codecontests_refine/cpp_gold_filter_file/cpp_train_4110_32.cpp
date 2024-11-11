#include <bits/stdc++.h>
int main() {
  int a, b, c, d, m, v;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  double m1 = (3 * a) / 10;
  double m2 = a - (a / 250) * c;
  if (m1 > m2)
    m = m1;
  else
    m = m2;
  double v1 = (3 * b) / 10;
  double v2 = b - (b / 250) * d;
  if (v1 > v2)
    v = v1;
  else
    v = v2;
  if (m > v) {
    printf("Misha\n");
  } else if (m < v) {
    printf("Vasya\n");
  } else if (m == v) {
    printf("Tie\n");
  }
  return 0;
}
