#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 2;
const double EPS = 1e-11;
const long long oo = 1e16;
int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  int fin = 0;
  while (fin == 0) {
    if (x1 + y1 <= max(x2, y2)) {
      fin = 1;
      break;
    }
    if (x1 - y1 > x2 - y2) {
      if (x1 >= 1)
        x1--;
      else
        y1--;
    } else if (x1 - y1 < x2 - y2) {
      if (y1 >= 1)
        y1--;
      else
        x1--;
    } else {
      if (x1 >= 1)
        x1--;
      else
        y1--;
    }
    if (x1 == 0 && y1 == 0) {
      fin = 1;
      break;
    }
    if ((x2 - 1 != x1 || y2 - 1 != y1) && x2 >= 1 && y2 >= 1) {
      x2--;
      y2--;
    } else if ((x2 != x1 || y2 - 1 != y1) && y2 >= 1) {
      y2--;
    } else if ((x2 - 1 != x1 || y2 != y1) && x2 >= 1) {
      x2--;
    }
    if (x2 == 0 && y2 == 0) {
      fin = 2;
      break;
    }
  }
  if (fin == 1)
    printf("Polycarp\n");
  else
    printf("Vasiliy\n");
}
