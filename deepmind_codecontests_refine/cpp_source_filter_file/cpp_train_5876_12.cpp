#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ls = s.length();
  string t;
  cin >> t;
  int lt = t.length();
  int i, j, k = 0;
  if (ls != lt) {
    cout << "YES" << endl;
  } else {
    for (i = 0; i < ls; i++) {
      for (j = lt - i - 1; j >= 0; j--) {
        if (s[i] == t[j]) {
          break;
        } else {
          k = 1;
          break;
        }
      }
      if (k == 1)
        break;
      else
        continue;
    }
    if (k == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
