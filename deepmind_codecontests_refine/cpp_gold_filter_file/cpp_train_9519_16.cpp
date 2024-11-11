#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, n, m, k, MIN, Min, y;
  double x;
  scanf("%d %d", &c, &d);
  scanf("%d %d", &n, &m);
  scanf("%d", &k);
  MIN = n * m - k;
  if (MIN <= 0)
    Min = 0;
  else {
    x = 1.0 * c / n;
    if (x > d) {
      Min = MIN * d;
    } else {
      Min = MIN / n * c;
      y = MIN % n;
      if (y * d > c)
        Min += c;
      else
        Min += d * y;
    }
  }
  printf("%d\n", Min);
  return 0;
}
