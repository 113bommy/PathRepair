#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, b, c;
  cin >> a >> b >> c;
  double x1 = ((-1 * b) + sqrt(b * b - 4 * a * c)) / (2 * a);
  double x2 = ((-1 * b) - sqrt(b * b - 4 * a * c)) / (2 * a);
  if (x1 > x2) {
    cout << setprecision(10) << x1 << endl;
    cout << setprecision(10) << x2 << endl;
  } else {
    cout << setprecision(10) << x1 << endl;
    cout << setprecision(10) << x2 << endl;
  }
}
