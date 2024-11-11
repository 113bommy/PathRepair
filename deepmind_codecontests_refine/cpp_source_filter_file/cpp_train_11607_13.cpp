#include <bits/stdc++.h>
using namespace std;
int main() {
  int xp, yp, xv, yv;
  cin >> xp >> yp >> xv >> yv;
  if (xp <= xv && yp <= yv)
    cout << "Polycarp" << endl;
  else if (max(xv, yv) + 1 < xp + yp)
    cout << "Vasiliy" << endl;
  else
    cout << "Polycarp" << endl;
  return 0;
}
