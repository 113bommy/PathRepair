#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  for (int i = s.length(); i > 0; i--) {
    if (isalpha(s[i])) {
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
          s[i] == 'U' || s[i] == 'Y' || s[i] == 'a' || s[i] == 'e' ||
          s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      break;
    }
  }
  return 0;
}
