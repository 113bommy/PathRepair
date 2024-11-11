#include <bits/stdc++.h>
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  int h, m, h1 = 0, m1 = 0, h2, m2, t1, t2, i;
  scanf("%d%d", &h2, &m2);
  if (n == 1) {
    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    if (t2 - t1 >= s + 1) {
      printf("0 0");
      return 0;
    } else {
      t2 = t2 + s + 1;
      h = t1 / 60;
      m = t1 % 60;
      printf("%d %d", h, m);
      return 0;
    }
  } else if ((h2 * 60 + m2) >= (s + 1)) {
    printf("0 0");
    return 0;
  } else
    h1 = h2;
  m1 = m2;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &h2, &m2);
    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    if (t2 - t1 >= 2 * s + 2) {
      t1 = t1 + s + 1;
      h = t1 / 60;
      m = t1 % 60;
      printf("%d %d", h, m);
      break;
    }
    h1 = h2;
    m1 = m2;
  }
  if (i == n) {
    t1 = h1 * 60 + m1 + (s + 1);
    h = t1 / 60;
    m = t1 % 60;
    printf("%d %d", h, m);
  }
  return 0;
}
