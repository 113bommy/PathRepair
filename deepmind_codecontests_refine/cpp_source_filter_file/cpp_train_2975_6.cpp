#include <bits/stdc++.h>
using namespace std;
template <typename T>
T POW(T b, T p) {
  T r = 1;
  while (p) {
    if (p & 1) r = (r * b);
    b = (b * b);
    p >>= 1;
  }
  return r;
}
template <typename T>
T BigMod(T b, T p, T m) {
  T r = 1;
  while (p) {
    if (p & 1) r = (r * b) % m;
    b = (b * b) % m;
    p >>= 1;
  }
  return r;
}
int main() {
  int x1, x2, x3, y1, y2, y3;
  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    cout << "3" << endl;
    cout << x1 + x3 - x2 << " " << y1 + x3 - y2 << endl;
    cout << x2 + x3 - x1 << " " << y2 + y3 - y1 << endl;
    cout << x1 + x2 - x3 << " " << y1 + y2 - y3 << endl;
  }
}
