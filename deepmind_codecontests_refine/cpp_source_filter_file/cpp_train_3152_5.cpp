#include <bits/stdc++.h>
const int mod = 1000000007;
const double PI = 3.1415926535897932384626433832795;
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, x, y, n;
    long long a2, b2, x2, y2, n2;
    cin >> a >> b >> x >> y >> n;
    a2 = a;
    b2 = b;
    x2 = x;
    y2 = y;
    n2 = n;
    long long min;
    if (a - n >= x) {
      a -= n;
    } else {
      n -= a - x;
      a = x;
      b = (((b - n) > (y)) ? b - n : y);
    }
    min = a * b;
    if (b2 - n2 >= y2) {
      b2 -= n2;
    } else {
      n2 -= b - y;
      b2 = y;
      a2 = (((a2 - n2) > (x2)) ? a2 - n2 : x2);
    }
    min = (((a2 * b2) < (min)) ? a2 * b2 : min);
    cout << min << '\n';
  }
}
