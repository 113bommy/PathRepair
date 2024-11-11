#include <bits/stdc++.h>
using namespace std;
int x, y;
void move(int &st, int j) {
  int xp = j / 2, yp = (j % 2) != xp;
  int k = 0;
  if (yp == 0)
    if (xp == 1)
      if (st == 1 || st == 3)
        k = 1;
      else
        k = 3;
    else if (st == 1 || st == 3)
      k = 3;
    else
      k = 1;
  if (st == 2 || st == 3) xp = 1 - xp, yp = 1 - yp;
  if (st == 1 || st == 3) swap(xp, yp);
  st += k;
  st %= 4;
  x *= 2;
  y *= 2;
  x += xp;
  y += yp;
}
int main() {
  int a, b;
  cin >> a >> b;
  int st = 0;
  for (int r = 1 << 2 * (a - 1); r > 0; r >>= 2) {
    int j = (b / r);
    move(st, j);
    b %= r;
  }
  cout << x << " " << y << endl;
}
