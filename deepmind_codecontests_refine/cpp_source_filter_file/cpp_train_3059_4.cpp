#include <bits/stdc++.h>
using namespace std;
int p, nr, i, j;
int put(int x, int y) {
  int rez = 1, i;
  while (y > 0)
    if (y % 2 == 0) {
      x *= x;
      x %= p;
      y /= 2;
    } else {
      rez *= x;
      rez %= p;
      --y;
    }
  return (rez);
}
int main(void) {
  cin >> p;
  for (i = 2; i < p; ++i) {
    bool ok1 = 1;
    for (j = 1; j < p - 1; ++j)
      if (put(i, j) == 1) {
        ok1 = 0;
        break;
      }
    if (ok1 == 1 && put(i, p - 1) == 1) ++nr;
  }
  cout << nr;
  return (0);
}
