#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x = 0, y = 0;
  scanf("%lld %lld", &n, &m);
  bool imp = false;
  for (int i = 0, j = 1; i < 63; i++, j <<= 1) {
    if ((n & j) != 0) x |= j;
    if (((n & j) != 0) != ((m & j) != 0)) {
      if (i == 0) {
        imp = true;
        break;
      }
      y |= j >> 1;
      if ((n & j) != 0) m -= (j << 1);
      if (m < 0) {
        imp = true;
        break;
      }
    }
  }
  if (imp) {
    printf("-1\n");
  } else if (x == 0) {
    if (y == 0)
      printf("0\n");
    else
      printf("2\n%lld %lld\n", y, y);
  } else if (y == 0) {
    printf("1\n%lld\n", x);
  } else if ((x ^ y) == x + y) {
    printf("2\n%lld %lld\n", x + y, y);
  } else {
    printf("3\n%lld %lld %lld\n", x, y, y);
  }
}
