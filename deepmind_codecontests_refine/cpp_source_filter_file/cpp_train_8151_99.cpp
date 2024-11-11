#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, g, h;
  cin >> a >> b >> c >> d >> e >> f >> g >> h;
  int x, y, z;
  x = (b * c) / g;
  y = d * e;
  z = f / h;
  int ans = min(min(x, y), z);
  cout << ans / 3;
  return 0;
}
