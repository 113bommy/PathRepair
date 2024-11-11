#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int i;
  int a, b, c, d, x, y;
  int z[t];
  for (int i = 1; i <= t; i++) {
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    if (c <= (a / 2))
      x = a - 1 - c;
    else
      x = c;
    if (d <= (b / 2))
      y = b - 1 - d;
    else
      y = d;
    if (a == 1) {
      z[i] = y;
      continue;
    }
    if (b == 1) {
      z[i] = x;
      continue;
    }
    if (a * y >= b * x)
      z[i] = a * y;
    else
      z[i] = b * y;
  }
  for (i = 1; i <= t; i++) cout << z[i] << "\n";
  return 0;
}
