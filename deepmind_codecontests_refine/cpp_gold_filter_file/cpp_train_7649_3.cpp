#include <bits/stdc++.h>
using namespace std;
void init() {
  cout << fixed;
  cout.precision(9);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
bool check(double a, double b, double c, double d, double x) {
  double mxad = a * d;
  double mnad = a * d;
  double mxbc = b * c;
  double mnbc = b * c;
  double cand;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      cand = (a + i * x) * (d + j * x);
      if (cand > mxad) mxad = cand;
      if (cand < mnad) mnad = cand;
      cand = (b + i * x) * (c + j * x);
      if (cand > mxbc) mxbc = cand;
      if (cand < mnbc) mnbc = cand;
    }
  }
  if (mnad > mxbc || mxad < mnbc) {
    return false;
  }
  return true;
}
int main() {
  init();
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  check(a, b, c, d, 0);
  double l = 0;
  double r = 10e10;
  for (int i = 0; i < 1000000; i++) {
    double mid = (l + r) / 2;
    if (check(a, b, c, d, mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << l << endl;
  return 0;
}
