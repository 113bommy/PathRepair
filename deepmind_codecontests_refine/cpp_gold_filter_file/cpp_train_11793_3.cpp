#include <bits/stdc++.h>
using namespace std;
int n, R, r;
long double pi = 3.141592653589793238462643383279;
long double eps = 0.0000000000001;
bool ok() {
  if (n == 1) {
    return r <= R;
  }
  if (n == 2) {
    return 2 * r <= R;
  }
  int d = R - r;
  int d2 = d * d;
  return d2 * cos(2 * pi / n) <= d2 - 2 * r * r + eps;
}
int main() {
  cin >> n >> R >> r;
  if (ok()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
