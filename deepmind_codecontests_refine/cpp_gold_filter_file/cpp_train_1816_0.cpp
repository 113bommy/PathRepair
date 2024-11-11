#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' &&
        s[i] != 'O' && s[i] != 'T' && s[i] != 'U' && s[i] != 'V' &&
        s[i] != 'W' && s[i] != 'X' && s[i] != 'Y') {
      cout << "NO";
      return 0;
    }
  }
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
