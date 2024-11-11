#include <bits/stdc++.h>
double sqrt2(int m) {
  double sqrts = (10 + m / 10) / 2;
  for (int i = 0; i < 25; i++) {
    sqrts = (sqrts + m / sqrts) / 2;
  }
  return sqrts;
}
int main() {
  int t;
  scanf("%d", &t);
  int det = 1 - 4 * 1 * (-2 * t);
  double x1 = (-1 + sqrt2(det)) / 2;
  double x2 = (-1 - sqrt2(det)) / 2;
  if ((x1 == (int)x1 || x2 == (int)x2) && (x1 > 0 || x2 > 0)) {
    printf("YES");
  } else
    printf("NO");
}
