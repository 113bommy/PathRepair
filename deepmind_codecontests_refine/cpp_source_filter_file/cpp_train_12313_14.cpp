#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a, y, x, t = 1, col = 1;
  cin >> a >> x >> y;
  while (y > a) {
    col++;
    if (t % 2 && t != 1) col++;
    t++;
    y -= a;
  }
  if (y == 0)
    cout << -1;
  else if (t % 2 == 0 || t == 1) {
    if (abs(x) < a)
      cout << col;
    else
      cout << -1;
  } else {
    if (x > 0 && x < a)
      cout << col + 1;
    else if (x < 0 && -x < a)
      cout << col;
    else
      cout << -1;
  }
}
