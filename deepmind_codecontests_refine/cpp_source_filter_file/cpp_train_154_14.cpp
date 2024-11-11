#include <bits/stdc++.h>
using namespace std;
const long double INF = 1e18;
pair<long double, pair<int, string> > Cal(long double x, long double y,
                                          long double z, string sx, string sy,
                                          string sz, int k, int p) {
  if (x < 1)
    return pair<long double, pair<int, string> >(-INF,
                                                 pair<int, string>(-10000, ""));
  if (x == 1)
    return pair<long double, pair<int, string> >(
        0, pair<int, string>(p, sx + "^" + sy + "^" + sz));
  pair<long double, pair<int, string> > a1 =
      pair<long double, pair<int, string> >(
          log(log(x)) + log(y) * z,
          pair<int, string>(-p, sx + "^" + sy + "^" + sz));
  pair<long double, pair<int, string> > a2 =
      pair<long double, pair<int, string> >(
          log(log(x)) + log(z) * y,
          pair<int, string>(-p - 1, sx + "^" + sz + "^" + sy));
  pair<long double, pair<int, string> > a3 =
      pair<long double, pair<int, string> >(
          log(log(x)) + log(y) + log(z),
          pair<int, string>(-p - 2, "(" + sx + "^" + sy + ")^" + sz));
  a1.first *= k;
  a2.first *= k;
  a3.first *= k;
  return max(max(a1, a2), a3);
}
int main() {
  long double x, y, z;
  cin >> x >> y >> z;
  pair<long double, pair<int, string> > a1, a2, a3;
  if (x >= 1 || y >= 1 || z >= 1) {
    a1 = Cal(x, y, z, "x", "y", "z", 1, 1);
    a2 = Cal(y, x, z, "y", "x", "z", 1, 5);
    a3 = Cal(z, x, y, "z", "x", "y", 1, 9);
  } else {
    a1 = Cal(1 / x, y, z, "x", "y", "z", -1, 1);
    a2 = Cal(1 / y, x, z, "y", "x", "z", -1, 5);
    a3 = Cal(1 / z, x, y, "z", "x", "y", -1, 9);
  }
  cout << max(max(a1, a2), a3).second.second;
  return 0;
}
