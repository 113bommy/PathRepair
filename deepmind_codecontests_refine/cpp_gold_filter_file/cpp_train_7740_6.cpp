#include <bits/stdc++.h>
using namespace std;
int main() {
  double xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  if (xa == xb) {
    if (xc == xa)
      cout << "TOWARDS\n";
    else if (yb > ya) {
      if (xc > xb)
        cout << "RIGHT\n";
      else if (xc < xb)
        cout << "LEFT\n";
    } else {
      if (xc < xb)
        cout << "RIGHT\n";
      else if (xc > xb)
        cout << "LEFT\n";
    }
  } else if (ya == yb) {
    if (yc == ya)
      cout << "TOWARDS\n";
    else if (xb > xa) {
      if (yc > yb)
        cout << "LEFT\n";
      else if (yc < yb)
        cout << "RIGHT\n";
    } else {
      if (yc < yb)
        cout << "LEFT\n";
      else if (yc > yb)
        cout << "RIGHT\n";
    }
  } else {
    if ((xa - xb) / (ya - yb) == (xb - xc) / (yb - yc))
      cout << "TOWARDS\n";
    else if (yc - ya - (xc - xa) * ((ya - yb) / (xa - xb)) > 0) {
      if (xb > xa)
        cout << "LEFT\n";
      else
        cout << "RIGHT\n";
    } else {
      if (xb > xa)
        cout << "RIGHT\n";
      else
        cout << "LEFT\n";
    }
  }
  return 0;
}
