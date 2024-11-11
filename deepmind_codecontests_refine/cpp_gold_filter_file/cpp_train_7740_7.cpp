#include <bits/stdc++.h>
using namespace std;
long long xa, xb, ya, yb, xc, yc;
long long ret;
long long com(long long x1, long long x2, long long y1, long long y2) {
  return x1 * y2 - x2 * y1;
}
int main() {
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  ret = com(xc - xa, xb - xa, yc - ya, yb - ya);
  if (ret == 0) {
    cout << "TOWARDS" << endl;
  } else if (ret < 0) {
    cout << "LEFT" << endl;
  } else {
    cout << "RIGHT" << endl;
  }
  return 0;
}
