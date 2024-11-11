#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int s = 0, c = 0;
  if (a > b) {
    while (a > 0 && b > 0) {
      c++;
      a--;
      b--;
    }
    if (a > 0) {
      s = s + a / 2;
    }
  } else if (b > a) {
    while (a > 0 && b > 0) {
      c++;
      a--;
      b--;
    }
    if (b > 0) {
      s = s + b / 2;
    }
  }
  printf("%d %d", c, s);
}
