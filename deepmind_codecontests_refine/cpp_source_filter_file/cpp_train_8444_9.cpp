#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long y, b, r;
  cin >> y >> b >> r;
  long long ans = 0;
  if (b >= y + 1 && r >= b + 1) ans = max(ans, 3 * y + 3);
  if (y >= b - 1 && r >= b + 1) ans = max(ans, b + b - 1 + b + 1);
  if (b >= r - 1 && y >= r - 2) ans = max(ans, 3 * r - 3);
  cout << ans << endl;
  return 0;
}
