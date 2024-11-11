#include <bits/stdc++.h>
using namespace std;
long long r, x, y, xx, yy, ile, reszta, wynik;
double odl;
int main() {
  cin >> r >> x >> y >> xx >> yy;
  odl = sqrt(((x - xx) * (x - xx) + (y - yy) * (y - yy)));
  cout << (int)(ceil)(odl / r / 2);
  return 0;
}
