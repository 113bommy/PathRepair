#include <bits/stdc++.h>
using namespace std;
int n, d, h, x, y;
int main() {
  scanf("%d%d%d", &n, &d, &h);
  if ((2 * h) < d || h > d || n <= d)
    printf("-1");
  else if (n > 2 && d == 1)
    printf("-1");
  else {
    x = 1;
    y = 2;
    while (x <= h) {
      printf("%d %d\n", x, y);
      x++;
      y++;
    }
    d -= h;
    x = 1;
    while (d) {
      printf("%d %d\n", x, y);
      x = y;
      y++;
      d--;
    }
    if (h == 1)
      x = 1;
    else
      x = 2;
    for (int i = y; i <= n; i++) printf("%d %d\n", x, i);
  }
}
