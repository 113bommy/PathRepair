#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxx = -2100000000, maxy = -2100000000, minx = 2100000000,
         miny = 2100000000, i, x, y;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    maxx = max(maxx, x + y);
    maxy = max(maxy, x - y);
    minx = min(minx, -x + y);
    miny = min(miny, -x - y);
  }
  printf("%d\n", maxx + minx + maxy + miny + 4);
  return 0;
}
