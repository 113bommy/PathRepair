#include <bits/stdc++.h>
int main() {
  int a, b, c, j, k = 0, l;
  scanf("%d", &a);
  int mn[a];
  int nm[a];
  for (b = 0; b < a; b++) {
    scanf("%1d", &mn[b]);
  }
  for (c = 0; c < a; c++) {
    scanf("%1d", &nm[c]);
  }
  for (j = 0; j < a; j++) {
    int p, t, s;
    if (mn[j] > nm[j]) {
      p = mn[j] - nm[j];
    } else {
      p = nm[j] - mn[j];
    }
    t = 10 - p;
    if (t > p) {
      k = k + p;
    } else {
      k = k + t;
    }
  }
  printf("%d", k);
  return 0;
}
