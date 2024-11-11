#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
string s;
long long x, y, n;
long long bx, by;
long long l_abs(long long x) {
  if (x < 0) return -x;
  return x;
};
int main() {
  cin >> x >> y >> n;
  double ie = 1.0 * x / y;
  bx = 0;
  by = 1;
  long long vv1, vv2, vn2;
  for (int a = 1; a <= x; a++) {
    double b = 1.0 * a * y / x;
    int b1 = (int)b, b2 = (int)b;
    if (b - (int)b != 0) {
      b1 = (int)b;
      b2 = b1 + 1;
    }
    if (b1 <= n && b1 != 0) {
      vv1 = x * by * b1;
      vv2 = y * bx * b1;
      vn2 = y * a * by;
      if (l_abs(vv1 - vv2) > l_abs(vv1 - vn2)) {
        bx = a;
        by = b1;
      };
    };
    if (b2 <= n && b2 != 0) {
      vv1 = x * by * b2;
      vv2 = y * bx * b2;
      vn2 = y * a * by;
      if (l_abs(vv1 - vv2) > l_abs(vv1 - vn2)) {
        bx = a;
        by = b2;
      };
    };
  };
  cout << bx << "/" << by << endl;
  return 0;
};
