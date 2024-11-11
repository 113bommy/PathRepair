#include <bits/stdc++.h>
int main() {
  int a, b, c, x, y, z, S1, S2;
  while (scanf("%d%d%d", &a, &b, &c) != EOF) {
    S1 = S2 = 0;
    scanf("%d%d%d", &x, &y, &z);
    if (a > x)
      S1 += (a - x) / 2;
    else
      S2 += x - a;
    if (b > y)
      S1 += (b - y) / 2;
    else
      S2 += y - b;
    if (c > z)
      S1 += (c - z) / 2;
    else
      S2 += z - c;
    if (S1 >= S2)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
