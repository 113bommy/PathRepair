#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, j, k, l;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a > b && a > c && a > d) {
    e = a;
    j = a - b;
    k = a - c;
    l = a - d;
  } else if (b > c && b > a && b > d) {
    e = b;
    j = b - a;
    k = b - c;
    l = b - d;
  } else if (c > a && c > b && d > c) {
    e = c;
    j = c - b;
    k = c - a;
    l = c - d;
  } else {
    e = d;
    j = d - b;
    k = d - c;
    l = d - a;
  }
  printf("%d %d %d  ", j, k, l);
  return 0;
}
