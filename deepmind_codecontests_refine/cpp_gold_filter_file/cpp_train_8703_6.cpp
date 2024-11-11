#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  bool ans = 0;
  for (int a = x; a <= y; a++) {
    double val = a * k;
    if (l <= val && val <= r) ans = 1;
  }
  if (ans)
    cout << "YES";
  else
    cout << "NO";
}
