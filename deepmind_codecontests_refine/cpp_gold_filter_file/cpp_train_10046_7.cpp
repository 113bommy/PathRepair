#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, xx, yy;
  scanf("%d%d%d%d%d", &n, &x, &y, &xx, &yy);
  if (x == xx && (x == 0 || x == n))
    printf("%d\n", abs(y - yy));
  else if (y == yy && (y == 0 || y == n))
    printf("%d\n", abs(x - xx));
  else {
    int a = y + yy + x + xx;
    int b = 2 * n + y + yy - x - xx;
    a = min(a, 4 * n - a);
    b = min(b, 4 * n - b);
    printf("%d\n", min(a, b));
  }
  return 0;
}
