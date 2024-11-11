#include <bits/stdc++.h>
int n, a, b;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b);
    if (b - a > 15) {
      printf("%d\n", a + 15);
      return 0;
    }
    a = b;
  }
  if (b + 15 > 90)
    b = 90;
  else
    b += 15;
  printf("%d\n", b);
}
