#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w = 0, e = 0, q = 0, a = 0;
  cin >> n;
  int t, x, y;
  while (n--) {
    cin >> t >> x >> y;
    if (t == 1) {
      w += x;
      e += y;
    } else {
      q += x;
      a += y;
    }
  }
  if (w >= e / 2) {
    cout << "LIVE" << endl;
  } else {
    cout << "DEAD" << endl;
  }
  if (q >= (a / 2)) {
    cout << "LIVE" << endl;
  } else {
    cout << "DEAD" << endl;
  }
  return 0;
}
