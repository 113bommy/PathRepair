#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long x, y, p, q;
    cin >> x >> y >> p >> q;
    if ((p == q && x != y) || (p == 0 && x != 0)) {
      puts("-1");
      continue;
    }
    if ((p == q && x == y) || (p == 0 && x == 0)) {
      puts("0");
      continue;
    }
    long long l = 0, r = 1e9;
    while (l < r - 1) {
      long long m = (l + r) / 2;
      long long a, b;
      a = p * m - x;
      b = q * m - y;
      if (a >= 0 && b >= a)
        r = m;
      else
        l = m;
    }
    cout << r * q - y << endl;
  }
  return 0;
}
