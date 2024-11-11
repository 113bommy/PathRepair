#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, g, h, i, j;
  cin >> a >> b >> c >> d;
  e = 3 * a / 10;
  f = 3 * b / 10;
  g = a - (a / 250) * c;
  h = b - (b / 250) * d;
  if (e > g)
    i = e;
  else
    i = g;
  if (f > h)
    j = f;
  else
    j = h;
  if (i > j)
    cout << "misha" << endl;
  else if (i == j)
    cout << "tie" << endl;
  else
    cout << "vasya" << endl;
  return 0;
}
