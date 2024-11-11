#include <bits/stdc++.h>
using namespace std;
int a, b, c, x, y, z, k, t;
int main() {
  cin >> a >> b >> c >> x >> y >> z;
  k = max(a - x, 0) / 2 + max(b - y, 0) / 2 + max(c - z, 0) / 2;
  t = max(x - a, 0) + max(y - b, 0) + max(z - c, 0);
  if (k >= t)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
