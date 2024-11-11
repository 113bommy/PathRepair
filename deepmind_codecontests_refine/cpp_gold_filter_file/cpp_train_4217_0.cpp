#include <bits/stdc++.h>
using namespace std;
double getLength(double a, double b) { return sqrt(a * a + b * b + a * b); }
double getArea(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
  double A[6], hexagon, x, y, z;
  for (int i = 0; i < 6; i++) {
    cin >> A[i];
  }
  x = getLength(A[0], A[1]);
  y = getLength(A[2], A[3]);
  z = getLength(A[4], A[5]);
  hexagon = getArea(x, y, z) + getArea(A[0], A[1], x) + getArea(A[2], A[3], y) +
            getArea(A[4], A[5], z);
  cout << (int)(hexagon / getArea(1.0, 1.0, 1.0)) << endl;
  return 0;
}
