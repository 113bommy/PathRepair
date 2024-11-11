#include <bits/stdc++.h>
using namespace std;
int r, x, y, xx, yy;
double d;
long long int cal(int z) { return (long long int)z * z; }
double dist(int a, int b, int c, int d) {
  return sqrt(cal(a - c) + cal(b - d));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> x >> y >> xx >> yy;
  d = dist(x, y, xx, yy);
  cout << (int)ceil(d / (2.0 * r)) << endl;
  return 0;
}
