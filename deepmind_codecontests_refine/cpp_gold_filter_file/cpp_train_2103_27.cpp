#include <bits/stdc++.h>
int a, b, c, d, k, T;
int main() {
  scanf("%d\n", &T);
  while (T--) {
    scanf("%d %d %d %d %d\n", &a, &b, &c, &d, &k);
    int x = a / c, y = b / d;
    x += ((a - x * c) > 0);
    y += ((b - y * d) > 0);
    if (x + y > k)
      printf("-1\n");
    else
      printf("%d %d\n", x, y);
  }
}
