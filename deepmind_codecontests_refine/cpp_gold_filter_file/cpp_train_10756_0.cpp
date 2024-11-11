#include <bits/stdc++.h>
using namespace std;
int x, y, a, b;
int main() {
  scanf("%d%d%d%d", &x, &y, &a, &b);
  if (x > y) {
    if (x + a <= y && x + b >= y)
      printf("FIRST\n%d\n", y);
    else if (a <= 0 && b >= 0)
      printf("DRAW\n");
    else if (a > 0)
      printf("DRAW\n");
    else if ((x - y) % (-a - b) == 0)
      printf("SECOND\n");
    else if ((x - y) % (-a - b) > -a || (x - y) % (-a - b) < -b)
      printf("DRAW");
    else
      printf("FIRST\n%d\n", y + ((x - y) / (-a - b) * (-a - b)));
  } else {
    if (x + a <= y && x + b >= y)
      printf("FIRST\n%d\n", y);
    else if (a <= 0 && b >= 0)
      printf("DRAW\n");
    else if (b < 0)
      printf("DRAW\n");
    else if ((y - x) % (a + b) == 0)
      printf("SECOND\n");
    else if ((y - x) % (a + b) < a || (y - x) % (a + b) > b)
      printf("DRAW");
    else
      printf("FIRST\n%d\n", y - ((y - x) / (a + b) * (a + b)));
  }
  return 0;
}
