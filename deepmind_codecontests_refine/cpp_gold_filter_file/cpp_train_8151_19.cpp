#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int x = 0, y = 0, z = 0;
  x = (k * l) / nl;
  y = c * d;
  z = p / np;
  x = x / n;
  y = y / n;
  z = z / n;
  if (x < y && x < z)
    cout << x;
  else if (y < z)
    cout << y;
  else
    cout << z;
  return 0;
}
