#include <bits/stdc++.h>
long double kv(long double k) {
  long double a = k * k;
  return (a);
}
using namespace std;
int main() {
  long double x1, y1, r1, x2, y2, r2, s1, s2, L1, L2;
  const long double pi = acos(-1.0);
  cout.precision(20);
  ;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  double vidst = sqrt(kv(x2 - x1) + kv(y2 - y1));
  if (r1 + r2 <= vidst)
    cout << 0;
  else if (r1 >= vidst + r2)
    cout << pi * kv(r2);
  else if (r2 >= vidst + r1)
    cout << pi * kv(r1);
  else {
    L1 = acos((kv(r1) + kv(vidst) - kv(r2)) / (2 * r1 * vidst));
    L2 = acos((kv(r2) + kv(vidst) - kv(r1)) / (2 * r2 * vidst));
    s1 = L1 * kv(r1) - cos(L1) * sin(L1) * kv(r1);
    s2 = L2 * kv(r2) - cos(L2) * sin(L2) * kv(r2);
    cout << s1 + s2 << endl;
  }
  return 0;
}
