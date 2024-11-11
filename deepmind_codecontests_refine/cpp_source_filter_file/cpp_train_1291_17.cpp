#include <bits/stdc++.h>
int main() {
  int r, h;
  scanf("%d %d", &r, &h);
  int n = (h / r);
  int remainder = h - n;
  n = 2 * n;
  if ((remainder + r) >= (r * 0.5 * (2.0 + sqrt(3.0)))) {
    n += 3;
  } else if (remainder >= (r / 2.0)) {
    n += 2;
  } else {
    n += 1;
  }
  printf("%d\n", n);
  return 0;
}
