#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, h, v, e;
  double area, decVol, incVol, currVol;
  cin >> d >> h >> v >> e;
  area = 3.141592654 * (d / 2.0) * (d / 2.0);
  currVol = area * h;
  decVol = (double)v;
  incVol = area * e;
  cout.precision(12);
  if (incVol >= decVol) {
    cout << "No" << endl;
    return 0;
  } else {
    cout << "YES" << endl << currVol / (decVol - incVol) << endl;
  }
}
