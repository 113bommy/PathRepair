#include <bits/stdc++.h>
unsigned L[9], R[9];
int main() {
  double r = 0.0, s, t, tmp;
  unsigned n, i, j, k, l;
  scanf("%u", &n);
  for (i = -1; ++i < n;) scanf("%u%u", L + i, R + i);
  for (i = 0; ++i <= 10;) {
    t = 0.0;
    for (j = 0; j < n; ++j) {
      if (R[j] <= i) continue;
      tmp = (double)(R[j] - (i < L[j] ? L[j] - 1 : i)) /
            (double)(R[j] - L[j] + 1);
      s = tmp;
      for (l = 0; l < n; ++l) {
        if (l == j) continue;
        if (L[l] > i) {
          s = 0.0;
          break;
        }
        s *= (double)((i > R[l] ? R[l] : i) - L[l] + 1) /
             (double)(R[l] - L[l] + 1);
      }
      t += s;
      s = tmp;
      for (l = 0; l < n; ++l) {
        if (l == j) continue;
        if (L[l] >= i) {
          s = 0.0;
          break;
        }
        s *= (double)((i > R[l] ? R[l] + 1 : i) - L[l]) /
             (double)(R[l] - L[l] + 1);
      }
      t -= s;
    }
    s = 1.0;
    for (l = 0; l < n; ++l) {
      if (L[l] > i) {
        s = 0.0;
        break;
      }
      s *= (double)((i > R[l] ? R[l] : i) - L[l] + 1) /
           (double)(R[l] - L[l] + 1);
    }
    t += s;
    s = 1.0;
    for (l = 0; l < n; ++l) {
      if (L[l] >= i) {
        s = 0.0;
        break;
      }
      s *= (double)((i > R[l] ? R[l] + 1 : i) - L[l]) /
           (double)(R[l] - L[l] + 1);
    }
    t -= s;
    tmp = 0.0;
    for (k = 0; k < n; ++k) {
      if (R[k] < i || L[k] > i) continue;
      s = 1.0 / (double)(R[k] - L[k] + 1);
      for (l = 0; l < n; ++l) {
        if (l == k) continue;
        if (L[l] >= i) {
          s = 0.0;
          break;
        }
        s *= (double)((i > R[l] ? R[l] + 1 : i) - L[l]) /
             (double)(R[l] - L[l] + 1);
      }
      tmp += s;
    }
    t -= tmp;
    r += t * (double)i;
  }
  printf("%.10lf\n", r);
  return 0;
}
