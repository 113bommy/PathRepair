#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%i", &t);
  while (t--) {
    long long a, b, c, i, l, r, m, n, x;
    scanf("%lli %lli %lli", &l, &r, &m);
    for (i = l; i <= r; i++) {
      x = m;
      n = (x + r - l) / i;
      if (n > 0) {
        a = i;
        x -= n * a;
        if (x == 0) {
          b = l;
          c = b;
        } else if (x > 0) {
          c = l;
          b = x + c;
        } else {
          b = l;
          c = b - x;
        }
        if (b >= l && b <= r && c >= l && c <= r) break;
      }
    }
    printf("%lli %lli %lli\n", a, b, c);
  }
}
