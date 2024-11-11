#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, r, x, y, a, b, a1, b1, f;
  double f1, k;
  cin >> r >> x >> y >> a >> b;
  a1 = abs(x - a);
  b1 = abs(y - b);
  f = a1 * a1 + b1 * b1;
  f1 = sqrt(f);
  if (x == a && y == b) {
    cout << "0" << endl;
  } else if (f1 <= r) {
    cout << "1" << endl;
  } else {
    k = (f1 / (2 * (double)r));
    cout << ceil(k) << endl;
  }
}
