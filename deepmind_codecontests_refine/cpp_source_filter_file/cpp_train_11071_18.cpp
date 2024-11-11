#include <bits/stdc++.h>
using namespace std;
int fib[1000];
inline int sqr(int x) { return x * x; }
int main() {
  int x1, y1, r1, R1;
  int x2, y2, r2, R2;
  scanf("%d%d%d%d", &x1, &y1, &r1, &R1);
  scanf("%d%d%d%d", &x2, &y2, &r2, &R2);
  double d = sqr(x1 - x2) + sqr(y1 - y2);
  int ret = 0;
  {
    if (sqr(r1 + R2) <= d || (d <= sqr(r2 - r1) && r2 >= r1) ||
        (d <= sqr(r1 - R2) && r1 >= R2))
      ++ret;
    if (sqr(r2 + R1) <= d || (d <= sqr(r1 - r2) && r1 >= r2) ||
        (d <= sqr(r2 - R1) && r2 >= R1))
      ++ret;
  }
  {
    if (sqr(R1 + R2) <= d || (d <= sqr(r2 - R1) && r2 >= R1) ||
        (d <= sqr(r1 - R2) && r1 >= R2))
      ++ret;
    if (sqr(R2 + R1) <= d || (d <= sqr(r1 - R2) && r1 >= R2) ||
        (d <= sqr(r2 - R1) && r2 >= R1))
      ++ret;
  }
  printf("%d\n", ret);
  return 0;
}
