#include <bits/stdc++.h>
using namespace std;
long long x, y, z;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> x >> y;
  z = x;
  for (int i = 2; i <= sqrt(y); i++) {
    if (y % i == 0) {
      long long s = 0, ss = 0;
      while (y % i == 0) {
        s++, y /= i;
      }
      long long n = x;
      while (n >= i) {
        ss += (n / i), n /= i;
      }
      z = min(z, ss / s);
    }
  }
  long long s = 0;
  while (y > 1 && x >= y) {
    s += (x / y);
    x /= y;
  }
  cout << ((s) ? min(z, s) : z) << endl;
  return 0;
}
