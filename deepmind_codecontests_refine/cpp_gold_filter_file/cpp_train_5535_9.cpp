#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, t, k, p, i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &x, &y, &t);
    if (m == 1 || x == y)
      printf("%d\n", t);
    else {
      if (t == 0)
        k = 0;
      else
        k = (t - 1) / (m - 1);
      p = t % (m - 1);
      if (k % 2 == 0) {
        if (p == 0)
          p = m;
        else
          p++;
        if (t == 0) p = 1;
        if (x <= y) {
          if (p <= x)
            printf("%d\n", t + y - p);
          else
            printf("%d\n", t + m - p + m - 1 + y - 1);
        } else {
          printf("%d\n", t + m - p + m - y);
        }
      } else {
        if (p == 0)
          p = 1;
        else
          p = m - p;
        if (x >= y) {
          if (p >= x)
            printf("%d\n", t + p - y);
          else
            printf("%d\n", t + p - 1 + m - 1 + m - y);
        } else {
          printf("%d\n", t + p - 1 + y - 1);
        }
      }
    }
  }
  return 0;
}
