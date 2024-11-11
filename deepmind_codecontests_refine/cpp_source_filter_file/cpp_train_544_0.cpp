#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, t, z, i, c;
  string s;
  cin >> t;
  while (t--) {
    z = 0;
    cin >> s;
    l = s.length();
    for (i = 0; i < l; i++) {
      if (s[i] == '0') {
        z++;
      }
    }
    c = min(z, l - c);
    if (c % 2 == 0) {
      cout << "NET" << endl;
    } else {
      cout << "DA" << endl;
    }
  }
}
