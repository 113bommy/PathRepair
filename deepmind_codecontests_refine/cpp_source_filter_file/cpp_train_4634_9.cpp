#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0;
  string s;
  cin >> s;
  if (s.length() > 5) {
    for (int i = 0; i < s.length(); i++) {
      if (x == 0) {
        if (s.at(i) == 'h') x = 1;
      }
      if (x == 1) {
        if (s.at(i) == 'e') x = 2;
      }
      if (x == 3) {
        if (s.at(i) == 'l') x = 4;
      }
      if (x == 2) {
        if (s.at(i) == 'l') x = 3;
      }
      if (x == 4) {
        if (s.at(i) == 'o') {
          x = 5;
          cout << "YES";
          break;
        }
      }
      if (x < 5 && i == s.length() - 1) cout << "NO";
    }
  } else
    cout << "NO";
  return 0;
}
