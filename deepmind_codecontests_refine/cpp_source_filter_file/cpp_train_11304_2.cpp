#include <bits/stdc++.h>
using namespace std;
class point {
 public:
  int id, val;
};
bool operator<(const point &a, const point &b) {
  if (a.val < b.val) return true;
  return false;
}
long double a, b;
int i, t;
long double get_int(long double a1) {
  return ((long double)(a1 * a1) / 8.0 + a1 * b) / (2.0 * a * b);
}
int main() {
  cin >> t;
  cout.setf(ios ::fixed | ios ::showpoint);
  cout.precision(6);
  for (i = 1; i <= t; i++) {
    cin >> a >> b;
    if (b == 0) {
      cout << "1.000000" << endl;
      continue;
    }
    if (a == 0) {
      cout << "0.000000" << endl;
      continue;
    }
    long double ans = 0.0;
    if (a <= 4 * b) {
      ans = get_int(a);
    } else {
      ans = get_int(4.0 * b) + (1 - (4.0 * b) / a);
    }
    cout << ans << endl;
  }
  return 0;
}
