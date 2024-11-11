#include <bits/stdc++.h>
int main() {
  int t, a, b, c, d, k, l, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    if (a % c != 0) l = (a / c) + 1;
    if (a % c == 0) l = (a / c);
    if (b % d != 0) m = (b / d) + 1;
    if (b % d == 0) m = (b / d);
    if ((l + m) <= k) printf("%d %d\n", l, m);
    if ((l + m) > k) printf("-1\n");
  }
}
