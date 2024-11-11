#include <bits/stdc++.h>
int main() {
  int a, b, d = 0, s = 0;
  scanf("%d%d", &a, &b);
  while (a != 0 && b != 0) {
    if (a >= 1 && b >= 1) {
      a--;
      b--;
      d++;
    }
  }
  s = (a + b) / 2;
  printf("%d %d", d, s);
  return 0;
}
