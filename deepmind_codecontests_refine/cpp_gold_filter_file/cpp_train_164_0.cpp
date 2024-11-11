#include <bits/stdc++.h>
using namespace std;
int collinear(long long x1, long long y1, long long x2, long long y2,
              long long x3, long long y3) {
  long long a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
  return a == 0 ? 1 : 0;
}
int main() {
  long long ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  long long ab = ax - bx;
  ab *= ab;
  ab += (ay - by) * (ay - by);
  long long cb = cx - bx;
  cb *= cb;
  cb += (cy - by) * (cy - by);
  if (ab == cb && !collinear(ax, ay, bx, by, cx, cy))
    cout << "Yes";
  else
    cout << "No";
}
