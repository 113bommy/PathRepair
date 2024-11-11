#include <bits/stdc++.h>
using namespace std;
const bool debug = !false;
const double epsilon = 1e-9;
double f(double x) {
  if (x < 0) return -f(-x);
  return int(x + epsilon);
}
bool ok(complex<double> x) {
  if (debug) cerr << x << endl;
  double a = x.imag(), b = x.real();
  return fabs(a - f(a)) <= epsilon && fabs(b - f(b)) <= epsilon;
}
int main() {
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  complex<double> A(ax, ay), B(bx, by), C(cx, cy), i(0, 1);
  if (fabs(cx) < epsilon && fabs(cy) < epsilon) {
    for (int k = 0; k < 4; k++, A *= i)
      if (A == B) {
        cout << "YES" << endl;
        return 0;
      }
    cout << "NO" << endl;
    return 0;
  }
  if (ok((B - A) / C) || ok((B - A * i) / C) || ok((B + A) / C) ||
      ok((B + A * i) / C))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
