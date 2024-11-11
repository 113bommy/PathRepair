#include <bits/stdc++.h>
int main(void) {
  int n, m, t, x1, x2, y1, y2;
  int res;
  scanf(" %*d %*d %d %d %d %d", &x1, &y1, &x2, &y2);
  n = (((x2 - x1) < 0) ? (-(x2 - x1)) : (x2 - x1));
  m = (((y2 - y1) < 0) ? (-(y2 - y1)) : (y2 - y1));
  if (n > m) t = n, n = m, m = t;
  if (m >= 5)
    res = 2;
  else if (m == 5) {
    if (n == 5)
      res = 2;
    else
      res = 1;
  } else
    res = 1;
  if (res == 1)
    printf("First\n");
  else
    printf("Second\n");
  return 0;
}
