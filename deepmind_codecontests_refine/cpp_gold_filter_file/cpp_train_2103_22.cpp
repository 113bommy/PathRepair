#include <bits/stdc++.h>
int main() {
  int t, a, b, c, d, k;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    int u;
    if (a % c == 0)
      u = a / c;
    else
      u = a / c + 1;
    int v;
    if (b % d == 0)
      v = b / d;
    else
      v = b / d + 1;
    if (u + v <= k)
      printf("%d %d\n", u, v);
    else
      printf("-1\n");
  }
  return 0;
}
