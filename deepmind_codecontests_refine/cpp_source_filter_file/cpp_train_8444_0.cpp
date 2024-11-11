#include <bits/stdc++.h>
int main() {
  int y, b, r, o, p, q, f = 0, l = 0, g = 0;
  scanf("%d %d %d", &y, &b, &r);
  o = y * 3 + 3;
  p = b * 3;
  q = r * 3 - 3;
  if (b >= y + 1 && r >= y + 2) {
    f = 1;
  }
  if (r >= b + 1 && y >= b - 1) {
    l = 1;
  }
  if (y >= r - 2 && b >= r - 1) {
    g = 1;
  }
  if (f == 1 && l == 0 && g == 0) {
    printf("%d", o);
    return 0;
  }
  if (f == 0 && l == 1 && g == 0) {
    printf("%d", p);
    return 0;
  }
  if (f == 0 && l == 0 && g == 1) {
    printf("%d", q);
    return 0;
  }
  if (f == 1 && l == 1 && g == 0) {
    if (o > p) {
      printf("%d", o);
      return 0;
    } else {
      printf("%d", p);
      return 0;
    }
  }
  if (f == 0 && l == 1 && g == 1) {
    if (q > p) {
      printf("%d", q);
      return 0;
    } else {
      printf("%d", p);
      return 0;
    }
  }
  if (f == 1 && l == 0 && g == 1) {
    if (o > q) {
      printf("%d", o);
      return 0;
    } else {
      printf("%d", q);
      return 0;
    }
  }
  if (f == 1 && l == 1 && g == 1) {
    if (o > p && o > q) {
      printf("%d", o);
      return 0;
    }
    if (p > q && p > o) {
      printf("%d", p);
      return 0;
    }
    if (q > p && q > o) {
      printf("%d", q);
      return 0;
    }
  }
}
