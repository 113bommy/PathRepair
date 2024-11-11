#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, r, x, y, k, i, f = 0;
  cin >> l >> r >> x >> y >> k;
  for (i = l; i <= r; i++) {
    if ((i / k) >= x && (i / k) <= y) {
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
