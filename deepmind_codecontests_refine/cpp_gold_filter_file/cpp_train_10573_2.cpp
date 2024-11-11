#include <bits/stdc++.h>
int main(int argc, char const *argv[]) {
  int a, b, c, d, x = 0, z = 0, n = 0, m = 0;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (a <= c && a <= d) {
    x = a;
  } else if (c <= a && c <= d) {
    x = c;
  } else if (d <= a && d <= c) {
    x = d;
  } else if (a == c && a == d) {
    x = a;
  }
  if (b < (a - x)) {
    printf("%d", x * 256 + b * 32);
  } else {
    printf("%d", x * 256 + 32 * (a - x));
  }
  return 0;
}
