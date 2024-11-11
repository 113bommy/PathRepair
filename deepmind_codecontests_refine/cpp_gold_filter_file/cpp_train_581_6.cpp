#include <bits/stdc++.h>
int D[6], J[6];
int main() {
  int x;
  scanf("%d", &x);
  for (int i = 5; i >= 0; --i) {
    D[i] = x % 10;
    x /= 10;
  }
  int cnt = 0;
  while (true) {
    int df = D[0] + D[1] + D[2] - D[3] - D[4] - D[5];
    if (df > 0) {
      int mn = D[0], ml = 0;
      for (int i = 1; i < 6; ++i) {
        if (i < 3 && mn < D[i]) {
          mn = D[i], ml = i;
        } else if (i >= 3 && mn < 9 - D[i]) {
          mn = 9 - D[i], ml = i;
        }
      }
      if (df >= mn) {
        D[ml] = (ml < 3 ? 0 : 9);
      } else {
        D[ml] += (ml < 3 ? -df : +df);
      }
    } else if (df < 0) {
      df = -df;
      int mn = 9 - D[0], ml = 0;
      for (int i = 1; i < 6; ++i) {
        if (i < 3 && mn < 9 - D[i]) {
          mn = 9 - D[i], ml = i;
        } else if (i >= 3 && mn < D[i]) {
          mn = D[i], ml = i;
        }
      }
      if (df >= mn) {
        D[ml] = (ml < 3 ? 9 : 0);
      } else {
        D[ml] += (ml < 3 ? +df : -df);
      }
    } else
      break;
    ++cnt;
  }
  printf("%d\n", cnt);
  return 0;
}
