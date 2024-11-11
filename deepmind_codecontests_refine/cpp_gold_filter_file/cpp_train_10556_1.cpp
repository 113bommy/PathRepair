#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x, y, b, tx, ty;
  cin >> x >> y;
  if (x > 0 && y > 0) {
    tx = abs(x);
    ty = abs(y);
    b = tx + ty;
    cout << "0 " << b << " " << b << " 0" << endl;
    return 0;
  }
  if (x < 0 && y > 0) {
    tx = abs(x);
    ty = abs(y);
    b = tx + ty;
    cout << "-" << b << " 0 0 " << b << endl;
    return 0;
  }
  if (x < 0 && y < 0) {
    tx = abs(x);
    ty = abs(y);
    b = tx + ty;
    cout << "-" << b << " 0 0 -" << b << endl;
    return 0;
  } else {
    tx = abs(x);
    ty = abs(y);
    b = tx + ty;
    cout << "0 -" << b << " " << b << " 0" << endl;
    return 0;
  }
  return 0;
}
