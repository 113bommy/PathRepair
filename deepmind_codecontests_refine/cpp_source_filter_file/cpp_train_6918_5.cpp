#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, c, d;
  scanf("%d %d", &a, &b);
  if (1 != a) {
    printf("1 0");
    return 0;
  }
  int lc = 0, count = 0;
  for (int i = 1; i < m; ++i) {
    scanf("%d %d", &c, &d);
    if (count != 0) {
      if (a == b && b == c) {
        ++count;
      } else {
        printf("%d %d", lc, count);
        return 0;
      }
    } else if (b == c) {
      count = 2;
      lc = b;
    } else if (b + 1 < c) {
      printf("%d 0", b + 1);
      return 0;
    }
    a = c, b = d;
  }
  if (count) {
    printf("%d %d", lc, count);
  } else if (b < m) {
    printf("%d 0", b + 1);
  } else {
    printf("OK");
  }
  return 0;
}
