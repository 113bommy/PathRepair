#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, l, v1, v2, k;
  cin >> n >> l >> v1 >> v2 >> k;
  double m = int(n) / int(k);
  double ans =
      l * v2 / (v1 * v2 - v2 * (v1 * v1 - v2 * v2) / (v1 + (2 * m - 1) * v2));
  cout << fixed << setprecision(10) << ans;
  return 0;
}
