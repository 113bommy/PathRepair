#include <bits/stdc++.h>
using namespace std;
double sq(double a) { return a * a; }
double dabs(double a) { return a < 0 ? -a : a; }
bool eq(double a, double b) { return dabs(a - b) < 0.00001; }
int main() {
  double r;
  cin >> r;
  for (int a = 1; a <= 10; a += 1) {
    for (int h = 1; h <= 10; h += 1) {
      if (r > a / 2.0) continue;
      if (!eq(1 / sq(r), 4 / sq(a) + 1 / sq(h))) continue;
      cout << a << " " << h << endl;
      return 0;
    }
  }
  return 0;
}
