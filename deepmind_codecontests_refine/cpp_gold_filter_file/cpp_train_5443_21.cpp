#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, h, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    h = (r + 1) / 2;
    if (l >= h) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
