#include <bits/stdc++.h>
int main() {
  int x1, y1, r1, R1, x2, y2, r2, R2;
  scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &r1, &R1, &x2, &y2, &r2, &R2);
  double p = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  printf("%d", (r1 + p <= r2 || R2 + p <= r1 || R2 + r1 <= p) +
                   (R1 + p <= r2 || R2 + p <= R1 || R2 + R1 <= p) +
                   (r2 + p <= r1 || R1 + p <= r2 || R1 + r2 <= p) +
                   (R2 + p <= r1 || R1 + p <= R2 || R1 + R2 <= p));
  return 0;
}
