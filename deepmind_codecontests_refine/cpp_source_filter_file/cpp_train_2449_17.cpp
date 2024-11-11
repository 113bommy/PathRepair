#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    if (a >= d - 1 && a <= 2 * d + 2)
      printf("YES\n");
    else if (b >= c - 1 && b <= 2 * c + 2)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
