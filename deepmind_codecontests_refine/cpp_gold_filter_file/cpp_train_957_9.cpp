#include <bits/stdc++.h>
using namespace std;
float maxeps, eps, maxs;
int maxi;
int min(int x, int y) {
  if (x > y)
    return y;
  else
    return x;
}
bool Eq(float x, float y) {
  if (abs(x - y) < 1e-7)
    return 1;
  else
    return 0;
}
bool BOE(float x, float y) {
  if ((x - y) > -1e-7)
    return 1;
  else
    return 0;
}
int main() {
  long long t1, t2, x1, x2, t0, y1, y2, i;
  float coef;
  scanf("%I64d%I64d%I64d%I64d%I64d", &t1, &t2, &x1, &x2, &t0);
  if (t1 == t2) {
    printf("%I64d %I64d", x1, x2);
    return 0;
  }
  if (t0 == t1) {
    printf("%I64d %I64d", x1, 0LL);
    return 0;
  }
  if (t0 == t2) {
    printf("%I64d %I64d", 0LL, x2);
    return 0;
  }
  coef = (t0 - t1) * 1.0 / (t2 - t0);
  maxeps = 1e9;
  for (i = 1; i <= x1; i++) {
    y1 = i;
    y2 = min(ceil(coef * y1), x2);
    eps = ((t1 * y1 + t2 * y2) * 1.0 / (y1 + y2) - t0);
    if (Eq(maxeps, eps)) {
      if (y1 + y2 > maxs) {
        maxeps = eps;
        maxi = i;
        maxs = y1 + y2;
      }
    } else if ((BOE(maxeps, eps)) && (BOE(eps, 0))) {
      maxeps = eps;
      maxi = i;
      maxs = y1 + y2;
    }
  }
  if (maxeps == 1e9) {
    printf("%I64d %I64d", 0LL, x2);
    return 0;
  }
  y1 = maxi;
  y2 = min(ceil(coef * y1), x2);
  printf("%I64d %I64d", y1, y2);
  return 0;
}
