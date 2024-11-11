#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while (getline(cin, s)) {
    for (int i = s.size(); i > 0; i--) {
      if (s[i] != ' ' && s[i] != '?') {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'u' &&
            s[i] != 'i' && s[i] != 'y' && s[i] != 'A' && s[i] != 'E' &&
            s[i] != 'O' && s[i] != 'U' && s[i] != 'I' && s[i] != 'Y') {
          cout << "NO" << endl;
          break;
        } else {
          cout << "YES" << endl;
          break;
        }
      }
    }
  }
  return 0;
}
