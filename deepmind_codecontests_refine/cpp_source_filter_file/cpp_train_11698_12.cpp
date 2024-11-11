#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, x, y, z, m, n, ans, p, q, a, b, c;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      x += b;
      y += b + c;
    } else {
      p += b;
      q += b + c;
    }
  }
  cout << ((x >= (y / 2)) ? "LIVE" : "DEAD") << endl;
  cout << ((p >= (y / 2)) ? "LIVE" : "DEAD") << endl;
  return 0;
}
