#include <bits/stdc++.h>
using namespace std;
long long wllabs(long long x) {
  if (x < 0)
    return -x;
  else
    return x;
}
bool can(long long x1, long long y1, long long x2, long long y2, long long x0,
         long long y0) {
  long long A = x2 - x0;
  long long B = y2 - y0;
  if (A == 0 && B == 0) return true;
  long long det = (x1) * (x1) + (y1) * (y1);
  if (det == 0) {
    return false;
  }
  long long al = A * x1 + B * y1;
  long long be = A * y1 - B * x1;
  if (wllabs(al) % det == 0 && wllabs(be) % det == 0) {
    return true;
  } else {
    return false;
  }
}
int main() {
  long long x1, y1, x2, y2, x0, y0;
  cin >> x0 >> y0;
  cin >> x2 >> y2;
  cin >> x1 >> y1;
  bool f1, f2, f3, f4;
  f1 = can(x1, y1, x2, y2, x0, y0);
  f2 = can(x1, y1, x2, y2, -x0, -y0);
  f3 = can(x1, y1, x2, y2, y0, -x0);
  f4 = can(x1, y1, x2, y2, -y0, x0);
  if (f1 || f2 || f3 || f4)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
