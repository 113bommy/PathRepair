#include <bits/stdc++.h>
using namespace std;
int d0, d1, t, res, a01, a00, a11, a10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a00 >> a01 >> a10 >> a11;
  d0 = sqrt(a00 * 2) + 1;
  d1 = sqrt(a11 * 2) + 1;
  (d0 < d1 ? d0 : d1) -= (!a01 & !a10);
  if (d0 * (d0 - 1) != 2 * a00 || d1 * (d1 - 1) != 2 * a11 ||
      d0 * d1 != a10 + a01)
    cout << "Impossible";
  else {
    for (int i = d0 + d1; i >= 1; i--)
      if (a01 >= d1) {
        cout << 0;
        a01 = a01 - d1;
      } else {
        cout << 1;
        d1--;
      }
  }
  return 0;
}
