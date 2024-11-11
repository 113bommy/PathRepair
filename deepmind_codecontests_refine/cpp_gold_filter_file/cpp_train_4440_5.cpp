#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b, t;
  cin >> r >> g >> b;
  r = r / 2 + r % 2;
  g = g / 2 + g % 2;
  b = b / 2 + b % 2;
  if ((r >= g) && (r >= b)) t = (r - 1) * 3 + 1;
  if ((g >= r) && (g >= b)) t = (g - 1) * 3 + 2;
  if ((b >= g) && (b >= r)) t = (b - 1) * 3 + 3;
  t += 29;
  cout << t;
  return 0;
}
