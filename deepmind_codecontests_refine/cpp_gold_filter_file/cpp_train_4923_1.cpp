#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, c0, c1, h, o, z, p;
  char str[1000];
  cin >> t;
  for (int i = 0; i < t; i++) {
    p = 0;
    cin >> n;
    cin >> c0;
    cin >> c1;
    cin >> h;
    cin >> str;
    o = 0;
    z = 0;
    for (int j = 0; j < n; j++) {
      if (str[j] == '0') {
        o++;
      } else {
        z++;
      }
    }
    if (h + c1 < c0) {
      p = p + o * (h + c1);
    } else {
      p = p + o * c0;
    }
    if (h + c0 < c1) {
      p = p + z * (h + c0);
    } else {
      p = p + z * c1;
    }
    cout << p << endl;
  }
  return 0;
}
