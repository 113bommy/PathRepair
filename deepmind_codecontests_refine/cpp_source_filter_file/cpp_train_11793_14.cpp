#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, R, r;
  cin >> n >> R >> r;
  if (R >= r && n <= 1)
    cout << "YES" << endl;
  else {
    double alpha =
        acos(((R - r) * (R - r) * 2 - 4 * r * r) / (2 * (R - r) * (R - r)));
    double ans = acos(-1) * 2 / alpha;
    if (ans - n >= -10e-6)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
