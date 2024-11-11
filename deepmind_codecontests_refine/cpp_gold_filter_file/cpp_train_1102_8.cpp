#include <bits/stdc++.h>
using namespace std;
double doMagic(double a, double b) {
  double res = 0.5;
  double h = (1.0) / (2.0 * a);
  double k = (h) / (4.0 * b);
  double A;
  double B;
  double S;
  if (a < 4 * b) {
    A = a;
    B = k * A;
    S = 0.5 * A * B;
    res += S;
  } else {
    A = 4 * b;
    B = h;
    S = 0.5 * A * B + (a - 4 * b) * h;
    res += S;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      cout << 1.0 << endl;
      continue;
    }
    if (a == 0)
      cout << 0.5 << endl;
    else
      cout << doMagic(a, b) << endl;
  }
exit:
  return (0);
}
