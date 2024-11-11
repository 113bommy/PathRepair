#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  long long v = 0, h = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (v == 0) {
        v++;
        cout << "1 1" << endl;
      } else {
        v = 0;
        cout << " 1 3" << endl;
      }
    }
    if (s[i] == '1') {
      if (h == 0) {
        h++;
        cout << "3 1" << endl;
      } else {
        h = 0;
        cout << "1 1" << endl;
      }
    }
  }
  return 0;
}
