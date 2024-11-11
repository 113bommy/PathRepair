#include <bits/stdc++.h>
using namespace std;
const double eps = 8e-5;
double x, h, l;
int main() {
  cin >> x;
  for (double h = 1.0; h <= 10.0; h += 1.0) {
    if (h < x) continue;
    l = h / (sqrt((h * h) / (x * x) - 1)) * 2.0;
    for (double q = 1.0; q <= 10.0; q += 1.0) {
      if (l - q < eps && q - l < eps) {
        cout << (int)q << ' ' << (int)h;
        return 0;
      }
    }
  }
}
