#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y, z;
  cin >> x >> y >> z;
  cin >> a >> b >> c;
  if (a < x) {
    cout << "NO\n";
    return 0;
  }
  int kek = min(a, x);
  a -= kek;
  x -= kek;
  kek = min(z, b);
  z -= kek;
  b -= kek;
  if (a + c < y + z) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
  return 0;
}
