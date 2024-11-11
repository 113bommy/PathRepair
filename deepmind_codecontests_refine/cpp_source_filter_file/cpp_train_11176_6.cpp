#include <bits/stdc++.h>
using namespace std;
bool z(int x) { return x == 0; }
int main() {
  int a1, b1, c1, a2, b2, c2;
  scanf("%d%d%d", &a1, &b1, &c1);
  scanf("%d%d%d", &a2, &b2, &c2);
  int res;
  if (z(a1) && z(b1) && z(c1) && z(a2) && z(a2) && z(b2) && z(c2))
    res = -1;
  else if ((z(a1) && z(b1)) || (z(a2) && z(b2))) {
    if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0))
      res = 0;
    else if (c1 == 0 || c2 == 0)
      res = -1;
  } else if (b1 == 0 || b2 == 0) {
    if (b1 == b2) {
      if (c1 * a2 == c2 * a1)
        res = -1;
      else
        res = 0;
    } else
      res = 1;
  } else {
    if (a1 * b2 == a2 * b1) {
      if (b1 * c2 == b2 * c2)
        res = -1;
      else
        res = 0;
    } else
      res = 1;
  }
  printf("%d\n", res);
}
