#include <bits/stdc++.h>
int main() {
  int a1, d, a, b, n = 0, s;
  scanf("%d %d", &a, &b);
  a1 = a;
  s = a;
  for (; a >= b;) {
    a = a1 / b;
    d = a1 % b;
    a1 = a + d;
    n = a + n;
  }
  printf("%d", s + n);
}
