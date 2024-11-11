#include <bits/stdc++.h>
int main() {
  int i1, i2;
  double l, t, e = 0.000003;
  scanf("%lf", &l);
  for (i1 = 1; i1 <= 10; i1++) {
    for (i2 = 1; i2 <= 10; i2++) {
      t = sqrt(((double)i1 / 2) * ((double)i1 / 2) + i2 * i2) * l -
          ((double)i1 / 2) * i2;
      if (t < e && t > (-1) * e) {
        printf("%d %d", i1, i2);
        i1 = 11;
        i2 = 11;
      }
    }
  }
  return 0;
}
