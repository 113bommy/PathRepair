#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    if (d >= a - 1 && d <= 2 * a + 2)
      printf("YES\n");
    else if (c >= b - 1 && c <= 2 * b + 2)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
