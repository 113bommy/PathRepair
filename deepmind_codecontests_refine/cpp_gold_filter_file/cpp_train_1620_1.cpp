#include <bits/stdc++.h>
using namespace std;
int D[20][20];
int n, m;
bool rec(long long a00, long long a01, long long a10, long long a11,
         long long zeros, long long ones, string& soFar, string& res) {
  if (a00 == 0 && a11 == 0 && a10 == 0 && a01 == 0) {
    if (zeros > 0)
      res = soFar + "0";
    else
      res = soFar + "1";
    return true;
  }
  if (a00 < 0 || a11 < 0 || a10 < 0 || a01 < 0) return false;
  soFar = soFar + "0";
  if (rec(a00 - zeros + 1, a01 - ones, a10, a11, zeros - 1, ones, soFar, res)) {
    return true;
  }
  soFar = soFar.substr(0, soFar.length() - 1) + "1";
  if (rec(a00, a01, a10 - zeros, a11 - ones + 1, zeros, ones - 1, soFar, res)) {
    return true;
  }
  soFar = soFar.substr(0, soFar.length() - 1);
  return false;
}
int main() {
  long long a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  double sqrt1 = sqrt(1.0 + 8 * a00);
  double sqrt2 = sqrt(1.0 + 8 * a11);
  long long c0 = (1 + sqrt1) / 2.0;
  long long c1 = (1 + sqrt2) / 2.0;
  if (!a01 && !a10) {
    if (!a11)
      c1 = 0;
    else
      c0 = 0;
  }
  if (c0 * c1 != a01 + a10 || (c1 * (c1 - 1)) / 2 != a11 ||
      (c0 * (c0 - 1)) / 2 != a00) {
    cout << "Impossible" << endl;
    return 0;
  }
  while (c1 + c0) {
    if (a01 >= c1) {
      a01 -= c1;
      cout << "0";
      --c0;
    } else {
      cout << "1";
      a10 -= c0;
      --c1;
    }
  }
}
