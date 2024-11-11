#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, s;
  double x1, x2, x3;
  cin >> n >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    cout << n << ' ' << 0 << ' ' << 0;
    return 0;
  }
  s = a + b + c;
  x1 = (a * n) / (s * 1.0);
  x2 = (b * n) / (s * 1.0);
  x3 = (c * n) / (s * 1.0);
  cout << setprecision(10) << fixed << x1 << ' ' << setprecision(10) << fixed
       << x2 << ' ' << setprecision(10) << fixed << x3 << '\n';
}
