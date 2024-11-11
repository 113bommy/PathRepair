#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, n;
  cin >> a >> b >> n;
  if (b == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (a == 0 || b % a != 0) {
    cout << "No solution\n";
    return 0;
  }
  int xhochn = b / a;
  if (xhochn < 0 && n % 2 == 0) {
    cout << "No solution\n";
    return 0;
  }
  double x = pow(abs(xhochn), 1.0 / n);
  if (xhochn < 0) {
    x = -x;
  }
  double xx = floor(x + 1e-7);
  if (abs(x - xx) < 1e-7) {
    cout << xx << endl;
    return 0;
  }
  cout << "No solution\n";
  return 0;
}
