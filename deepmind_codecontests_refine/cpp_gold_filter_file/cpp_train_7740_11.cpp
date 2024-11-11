#include <bits/stdc++.h>
const long double pie = 3.1415926535;
using namespace std;
bool br1, br2, br;
long long n, k, x, y, z, mini, maxi, l, ind, ini, sum, t, len, r, q, imini, w,
    m;
string s, s1, s2;
struct Point {
  long long X, Y;
  static long long getDir(Point a, Point b, Point c) {
    return ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
  }
};
void solve() {
  Point A, B, C;
  cin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y;
  m = A.getDir(A, B, C);
  if (m == 0)
    cout << "TOWARDS" << endl;
  else if (m > 0)
    cout << "LEFT" << endl;
  else
    cout << "RIGHT" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
