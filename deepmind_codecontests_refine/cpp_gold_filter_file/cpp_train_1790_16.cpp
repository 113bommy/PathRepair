#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    double x;
    cin >> x;
    if (x == 1) {
      cout << 1 << endl;
      continue;
    } else if (x == 2) {
      cout << 2 << endl;
      continue;
    }
    int res = abs((ceil(x / 2.0) * 2.0) - x);
    cout << res << endl;
  }
}
