#include <bits/stdc++.h>
using namespace std;
int vp, vd, c, f, t, j, k;
double i;
int main() {
  cin >> vp >> vd >> t >> f >> c;
  if (vp > vd) {
    cout << 0 << endl;
    return 0;
  }
  for (i = t; i < c / vp;)
    if ((vp * i) / (vd - vp) + i >= c)
      break;
    else {
      ++k;
      i += 2 * ((vp * i) / (vd - vp)) + f;
    }
  cout << k << endl;
  return 0;
}
