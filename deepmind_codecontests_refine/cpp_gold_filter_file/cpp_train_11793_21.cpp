#include <bits/stdc++.h>
using namespace std;
int main() {
  double r, R, n;
  cin >> n >> R >> r;
  if (r > R) {
    cout << "NO";
    return 0;
  }
  if (n == 1.0 && r <= R) {
    cout << "YES";
    return 0;
  }
  if (r == R) {
    if (n == 1.0)
      cout << "YES";
    else
      cout << "NO";
    return 0;
  }
  double alpha = acos(-((2 * r * r - (R - r) * (R - r)) / ((R - r) * (R - r))));
  double q = (2.0 * acos(-1.0)) / alpha;
  if (q - n > -0.0000001)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
