#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
double ax, ay, bx, by, cx, cy;
int main() {
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;
  if ((ax - bx) * (by - cy) == (ay - by) * (bx - cx)) {
    cout << "TOWARDS";
    return 0;
  }
  double aa = (ay - by);
  double bb = (bx - bx);
  double cc = (ax * by - bx * ay);
  double d = (aa * cx + bb * cy + cc) / sqrt(aa * aa + bb * bb);
  if (d > 0)
    cout << "LEFT";
  else
    cout << "RIGHT";
  return 0;
};
