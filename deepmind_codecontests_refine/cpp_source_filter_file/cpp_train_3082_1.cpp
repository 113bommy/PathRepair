#include <bits/stdc++.h>
int main() {
  int a, b, l, r;
  scanf("%d%d%d%d", &a, &b, &l, &r);
  int len = r - l + 1;
  if (len >= a + b + a) {
    if (a > b) {
      printf("%d", a + a - b);
    } else {
      printf("%d", a + 1);
    }
    return 0;
  }
  int base = a + b;
  l = l - (l - 1) / base * base;
  r = l + len - 1;
  int ans = 0;
  if (l <= a && r <= a) {
    ans = len;
  } else if (l <= a && r > a && r <= base) {
    ans = a - l + 1;
  } else if (l <= a && r > base) {
    if (a > b) {
      if (r - base >= l) {
        if (l - 1 > b) {
          ans = a + r - base - l + 1;
        } else {
          ans = a + r - base - b;
        }
      } else {
        ans = r - base + a - l + 1;
      }
    } else {
      if (r - base >= l) {
        ans = a;
      } else {
        ans = r - base + a - l + 1;
      }
    }
  } else if (l > a && l <= base && r <= base) {
    ans = 1;
  } else if (l > a && l <= base && r > base && r <= base + a) {
    ans = 1 + r - base;
  } else if (l > a && l <= base && r > base + a && r <= 2 * base) {
    ans = 1 + a;
  } else if (l > a && l <= base && r > 2 * base) {
    if (a > b) {
      if (r - 2 * base > b) {
        ans = a + 1 + r - 2 * base - b;
      } else {
        ans = a + 1;
      }
    } else {
      ans = a + 1;
    }
  }
  printf("%d\n", ans);
}
