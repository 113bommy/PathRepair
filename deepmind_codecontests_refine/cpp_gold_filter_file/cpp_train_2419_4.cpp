#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    cin >> a >> b;
    e = a % b;
    if (e == 0 && a >= b) {
      cout << "0" << endl;
      continue;
    } else {
      d = a % b;
      c = b - d;
      cout << c << endl;
    }
  }
  return 0;
}
