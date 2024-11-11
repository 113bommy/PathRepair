#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  long long i, a, n, x, y;
  while (cin >> n >> x >> y) {
    long long lcm, ttt;
    lcm = x / gcd(x, y) * y;
    ttt = lcm / y + lcm / x;
    while (n--) {
      cin >> a;
      if (a % ttt == 0 || (a + 1) % ttt == 0) {
        cout << "Both" << endl;
        continue;
      }
      a = a % (ttt);
      double t, tx, ty;
      t = a * 1.0 / (ttt);
      tx = t * x;
      ty = t * y;
      tx = int(tx);
      tx += 1;
      tx = tx * 1.0 / x;
      ty = int(ty);
      ty += 1;
      ty = ty * 1.0 / y;
      if (tx - ty > double(0.000000000000001))
        cout << "Vova" << endl;
      else
        cout << "Vanya" << endl;
    }
  }
  return 0;
}
