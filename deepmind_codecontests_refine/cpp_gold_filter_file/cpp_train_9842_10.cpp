#include <bits/stdc++.h>
using namespace std;
int main() {
  long double d, h, v, e, t, pi = 4 * atan(1);
  cin >> d >> h >> v >> e;
  t = 4 * v / (pi * d * d);
  if (t > e) {
    t = h / (t - e);
    cout << "YES" << endl;
    cout << t;
  } else
    cout << "NO" << endl;
  return 0;
}
