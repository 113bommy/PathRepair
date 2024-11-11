#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, c = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'h' && c == 0) {
      c = 1;
    }
    if (s[i] == 'e' && c == 1) {
      c = 2;
    }
    if (s[i] == 'i' && c == 2) {
      c = 3;
    }
    if (s[i] == 'd' && c == 3) {
      c = 4;
    }
    if (s[i] == 'i' && c == 4) {
      c = 5;
    }
    if (c == 5) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
