#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int _t[6];
int main() {
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &_t[i]);
  }
  long long a, b, x1, y1, x2, y2;
  a = 2 * _t[0];
  b = 2 * _t[1];
  x1 = _t[2] - _t[3];
  y1 = _t[2] + _t[3];
  x2 = _t[4] - _t[5];
  y2 = _t[4] + _t[5];
  long long X1 = x1 / b + (x1 > 0);
  long long X2 = x2 / b + (x2 > 0);
  long long Y1 = y1 / a + (y1 > 0);
  long long Y2 = y2 / a + (y2 > 0);
  long long D = max(abs(X1 - X2), abs(Y1 - Y2));
  cout << D << endl;
  return 0;
}
