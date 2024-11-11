#include <bits/stdc++.h>
const double f = sqrt(5.0);
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 1) {
      int a;
      scanf("%d", &a);
      if (a == 0)
        puts("BitAryo");
      else
        puts("BitLGM");
    }
    if (n == 3) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (a ^ b ^ c)
        puts("BitLGM");
      else
        puts("BitAryo");
    }
    if (n == 2) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (a > b) std::swap(a, b);
      int t = b - a;
      if (a == (int)(t * (1 + f) / 2))
        puts("BitAryo");
      else
        puts("BitLGM");
    }
  }
}
