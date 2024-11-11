#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, r, x, y, k, i, f = 0;
  cin >> l >> r >> x >> y >> k;
  for (i = x; i <= y; i++) {
    if ((i * k) >= l && (i * k) <= r) {
      f = 1;
      break;
    } else
      continue;
  }
  if (f == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
