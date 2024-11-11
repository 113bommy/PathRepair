#include <bits/stdc++.h>
using namespace std;
int main() {
  long double n, R, r;
  cin >> n >> R >> r;
  if (r <= R / 2) {
    long double angle = 2 * asin(r / (R - r));
    cout << (angle * n < 4 * acos(0) + 1E-9 ? "YES" : "NO");
  } else if (r <= R) {
    cout << (n == 1 ? "YES" : "NO");
  } else {
    cout << "NO";
  }
  return 0;
}
