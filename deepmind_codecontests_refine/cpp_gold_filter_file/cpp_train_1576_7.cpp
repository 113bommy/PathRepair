#include <bits/stdc++.h>
using namespace std;
double DegreesToRadians(double degrees) { return degrees * 3.141592653 / 180; }
int main() {
  double n, r;
  cin >> n >> r;
  double sine = 1.0 * sin(DegreesToRadians(180.0 / n * 1.0));
  cout << fixed << setprecision(10) << (r * 1.0 * sine) / (1.0 * (1 - sine));
  return 0;
}
