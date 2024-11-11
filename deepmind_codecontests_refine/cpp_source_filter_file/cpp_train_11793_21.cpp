#include <bits/stdc++.h>
using namespace std;
int main() {
  size_t n;
  double R, r;
  while (cin >> n >> R >> r) {
    if (r > R * 0.5) {
      if (n == 1 && r <= R)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      double rad = 2 * asin(r / (R - r));
      size_t m = floor((2 * acos(-1.0) + 1e-6) / rad);
      if (m >= n)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
