#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  while (~scanf("%d%d%d%d", &a, &b, &c, &d)) {
    if (d <= 2 * c && 2 * d >= c) {
      c = max(c, d);
      if (2 * c >= b) {
        b = 2 * c + 1;
      }
      a = max(a, b + 1);
      printf("%d\n%d\n%d\n", a, b, c);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
