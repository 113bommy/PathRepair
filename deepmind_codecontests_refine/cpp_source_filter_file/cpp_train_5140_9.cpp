#include <bits/stdc++.h>
using namespace std;
long long a, b, c, i, j, m, s = 0, g, h, s1;
long long x, d, n, y;
void ret() {
  s = 0;
  if (x + d > n) s += ((x + d) - n) * ((x + d) - n);
  if (x - d <= 0) s += ((x - d) - 1) * ((x - d) - 1);
  if (y + d > n) s += ((y + d) - n) * ((y + d) - n);
  if (y - d <= 0) s += ((y - d) - 1) * ((y - d) - 1);
}
int main() {
  cin >> n >> x >> y >> c;
  a = 0, b = n + 1;
  if (c == 1)
    cout << 0 << endl;
  else {
    while (b - a > 1) {
      d = (a + b) / 2;
      s1 = ((d + 1) * (d + 1)) + (d * d);
      ret();
      s1 -= s;
      if (x + d > n && y - d <= 0) {
        g = (x + d) - n;
        h = abs((y - d) - 1);
        if (g + h > (d + 1))
          h = (g + h) - (d + 2) + 1, h = (h * (h + 1)) / 2, s1 += h;
      }
      if (x + d > n && y + d > n) {
        g = (x + d) - n;
        h = (y + d) - n;
        if (g + h > (d + 1))
          h = (g + h) - (d + 2) + 1, h = (h * (h + 1)) / 2, s1 += h;
      }
      if (x - d <= 0 && y + d > n) {
        g = abs((x - d) - 1);
        h = (y + d) - n;
        if (g + h > (d + 1))
          h = (g + h) - (d + 2) + 1, h = (h * (h + 1)) / 2, s1 += h;
      }
      if (x - d <= 0 && y - d <= 0) {
        g = abs((x - d) - 1);
        h = abs((y - d) - 1);
        if (g + h > (d + 1))
          h = (g + h) - (d + 2) + 1, h = (h * (h + 1)) / 2, s1 += h;
      }
      if (s1 >= c)
        b = (a + b) / 2;
      else
        a = (a + b) / 2;
    }
    cout << ((a + b) / 2) + 1 << endl;
  }
  return 0;
}
