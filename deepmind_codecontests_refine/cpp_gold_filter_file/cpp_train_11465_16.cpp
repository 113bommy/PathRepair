#include <bits/stdc++.h>
using namespace std;
long double pp(long double n) {
  long double l = 1;
  long double r = 2;
  while (abs(l - r) >= 1e-12) {
    long double m = (l + r) / 2;
    if ((n - m) - (n / m) > 0)
      r = m;
    else
      l = m;
  }
  return r;
}
int main() {
  int q;
  cin >> q;
  long double n;
  for (int i = 0; i < q; i++) {
    cin >> n;
    if (n == 0) {
      cout << "Y 0.000000000 0.000000000" << endl;
    } else if (n == 1 || n == 2 || n == 3) {
      cout << "N" << endl;
    } else {
      cout << fixed << setprecision(9) << "Y " << n - pp(n) << " " << pp(n)
           << endl;
    }
  }
}
