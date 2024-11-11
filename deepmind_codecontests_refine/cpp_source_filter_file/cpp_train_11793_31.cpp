#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double n, R, r;
  cin >> n >> R >> r;
  if (r > R) return cout << "NO", 0;
  if (r == R) {
    if (n <= 2)
      return cout << "YES", 0;
    else
      return cout << "NO", 0;
  }
  if (2 * r > R) {
    if (n <= 1)
      return cout << "YES", 0;
    else
      return cout << "NO", 0;
  }
  if (2 * r <= R) {
    double h = R - r;
    double t = atan2(r, (double)sqrt(h * h - r * r));
    if (t * n - PI > 0.0000000000000001)
      cout << "NO";
    else
      cout << "YES";
  }
  return 0;
}
