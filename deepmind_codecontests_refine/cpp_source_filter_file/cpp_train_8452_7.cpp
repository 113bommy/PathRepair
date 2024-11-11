#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n, x, a, b, c;
    scanf("%d%d%d%d", &n, &x, &a, &b);
    if (a > b) {
      c = b;
      b = a;
      a = c;
    }
    if ((a - b + x) > (n - 1))
      printf("%d\n", --n);
    else
      printf("%d\n", (a - b + x));
  }
}
