#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, d, m, g, p, b, x, y, z1, z;
  cin >> a >> d >> m >> g >> p >> b;
  if (g < a) {
    cout << "NO" << endl;
    return 0;
  } else {
    x = g - a;
  }
  y = x + p;
  if (y < d) {
    cout << "NO" << endl;
    return 0;
  } else {
    z = y - d;
  }
  z1 = y + b;
  if (z1 < m) {
    cout << "NO" << endl;
    return 0;
  } else {
    cout << "YES" << endl;
    return 0;
  }
}
