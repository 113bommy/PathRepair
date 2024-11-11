#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, h, m;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> h >> m;
    if (h == 0 && m == 0) {
      cout << "0" << endl;
    } else if (h == 0 && m > 0) {
      cout << (24 * 60) - m << endl;
    } else if (h > 0 && m == 0) {
      cout << (24 - h) * 60 << endl;
    } else if (h > 0 && m > 0) {
      cout << (23 - h) * 60 + (60 - m) << endl;
    }
  }
  return 0;
}
