#include <bits/stdc++.h>
using namespace std;
bool iseq(double a, double b) { return (a - 1e-9 < b && b < a + 1e-9); }
int main() {
  int x, y;
  while (cin >> x >> y) {
    if (x == 0 || y == 0) {
      cout << "block" << endl;
      continue;
    }
    bool flg = true;
    if ((x > 0 && y > 0) || (x < 0 && y < 0)) flg = false;
    double dist = sqrt(x * x + y * y);
    int idist = dist;
    if (iseq(dist, (double)idist)) {
      cout << "block" << endl;
      continue;
    }
    if (flg == false) {
      if (idist % 2 == 0)
        cout << "block" << endl;
      else
        cout << "white" << endl;
    } else {
      if (idist % 2 == 0)
        cout << "white" << endl;
      else
        cout << "block" << endl;
    }
  }
  return 0;
}
