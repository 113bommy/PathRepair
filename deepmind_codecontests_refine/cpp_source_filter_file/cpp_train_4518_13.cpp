#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  if (a == 0) {
    if (b == 0) {
      cout << "1";
    } else {
      cout << "No solution";
    }
    return 0;
  }
  double x = pow(fabs(double(b) / double(a)), 1.0 / double(n));
  int xx = x + 0.5;
  if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
    if (n % 2 == 0) {
      cout << "No solution";
      return 0;
    }
    xx *= -1;
  }
  if (a * int(pow(double(xx), n) + 0.5) == b) {
    cout << xx;
  } else {
    cout << "No solution";
  }
  return 0;
}
