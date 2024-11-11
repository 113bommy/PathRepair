#include <bits/stdc++.h>
using namespace std;
int main() {
  int xp, yp, xv, yv;
  cin >> xp >> yp >> xv >> yv;
  bool polyw = false;
  if ((xp == 0 && yp == 1) || (xp == 1 && yp == 0))
    polyw = true;
  else if (xp <= xv && yp <= yv)
    polyw = true;
  else if (xp + yp <= (xv < yv ? xv : yv))
    polyw = true;
  cout << (polyw ? "Polycarp" : "Vasiliy") << endl;
  return 0;
}
