#include <bits/stdc++.h>
using namespace std;
int main() {
  int xp, yp, xv, yv;
  while (cin >> xp >> yp >> xv >> yv) {
    int p = xp + yp;
    if (p <= max(xv, yv) || (xp <= xv && yp <= yv))
      cout << "Polycarp" << endl;
    else
      cout << "Vasiliy" << endl;
  }
  return 0;
}
