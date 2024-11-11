#include <bits/stdc++.h>
int main() {
  int a, b, n;
  scanf(" %d %d %d", &n, &a, &b);
  bool x = false;
  if (b < 0) {
    x = true;
  }
  if (x == false) {
    a += b;
    if (a % n == 0) {
      printf("%d", n);
      return 0;
    } else {
      printf("%d", a % n);
      return 0;
    }
  } else {
    a += b;
    if (a < 0) {
      a = n + a;
    }
    if (a % n == 0) {
      printf("%d", n);
      return 0;
    } else {
      printf("%d", a % n);
      return 0;
    }
  }
}
