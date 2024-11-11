#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r, d;
    cin >> l >> r >> d;
    int x, i = 1;
    if (d < l) {
      x = d * 1;
    } else if (d >= l) {
      r = r / d;
      x = (r + 1) * d;
    }
    cout << x << endl;
  }
  return 0;
}
