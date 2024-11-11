#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, sum, cnt, ans, a[15];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = (0); i <= (10); i++) {
    cin >> a[i];
  }
  for (int i = (10); i >= (0); i--) {
    n = abs(a[i]);
    double res = sqrt(n) + a[i] * a[i] * a[i] * 5.0;
    if (res > 400)
      cout << "f(" << a[i] << ") = MAGNA NIMIS!" << endl;
    else
      cout << fixed << setprecision(2) << "f(" << a[i] << ") = " << res << endl;
  }
  return 0;
}
