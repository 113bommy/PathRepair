#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() <= 2) {
      cout << s << endl;
      continue;
    } else if (s.find('1') == s.npos || s.find('0') == s.npos)
      cout << s << endl;
    else {
      for (int i = 0; i < s.size(); i++) {
        if (i == 0)
          cout << s[i];
        else {
          if (s[i - 1] == s[i]) {
            if (s[i] == '1')
              cout << '0';
            else
              cout << '1';
          }
          cout << s[i];
        }
      }
      cout << endl;
    }
  }
}
