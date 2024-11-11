#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, c1 = 0, c2 = 0, i1 = 0, i2 = 0, t, cou = 0;
  cin >> x >> y;
  if (y < x) {
    t = x;
    x = y;
    y = t;
  }
  while (x != y) {
    if (c1 <= c2) {
      if (c1 == 0) c1 = 1;
      x++;
      i1++;
      c1 += i1;
      cou += i1;
    } else {
      if (c2 == 0) c2 = 1;
      y--;
      i2++;
      c2 += i2;
      cou += i2;
    }
  }
  cout << cou;
  return 0;
}
