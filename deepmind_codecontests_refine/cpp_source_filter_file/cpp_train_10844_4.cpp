#include <bits/stdc++.h>
using namespace std;
signed main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k2 = t.size();
    int k1 = s.size();
    if (k1 > k2) {
      cout << "NO" << endl;
    } else {
      int j = 0;
      int r = 0;
      int p = 0;
      for (int i = 0; i < k2; i++) {
        if (t[i] == s[j] && j < k1) {
          j++;
        } else {
          if (i > 0 && r == 0) {
            if (t[i] != t[i - 1]) {
              r = 1;
              cout << "NO" << endl;
            }
          }
          if (i == 0 && r == 0) {
            r = 1;
            cout << "NO" << endl;
          }
        }
      }
      if (r == 0 && j == k1) {
        cout << "YES" << endl;
      } else if (j != k1 - 1 && r == 0) {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
