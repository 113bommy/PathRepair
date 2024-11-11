#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z, n, m;
  cin >> a >> b >> c >> x >> y >> z;
  n = max(0, x - a) + max(0, y - b) + max(0, z - c);
  m = max(0, a - x) / 2 + max(0, b - y) / 2 + max(0, c - z) / 2;
  if (m >= n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
