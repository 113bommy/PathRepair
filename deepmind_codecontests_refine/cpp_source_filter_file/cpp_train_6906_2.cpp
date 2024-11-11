#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, k = 0;
  string s;
  while (getline(cin, s))
    ;
  {
    for (i = 0; i < (int)s.length(); i++) {
      if (s[i] != ' ') break;
    }
    if (i == (int)s.length() || s[i] != '#') {
      if (k == 2) cout << endl;
      for (i = 0; i < (int)s.length(); i++) {
        if (s[i] != ' ') cout << s[i];
      }
      k = 1;
    } else {
      if (k) {
        cout << endl;
      }
      cout << s;
      k = 2;
    }
  }
  cout << endl;
  return 0;
}
