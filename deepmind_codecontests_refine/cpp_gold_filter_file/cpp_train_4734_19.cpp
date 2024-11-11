#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int i = s.size();
  for (i = i - 2; i >= 0; i--) {
    if (s[i] == ' ')
      continue;
    else {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == 'y' || s[i] == 'A' || s[i] == 'E' ||
          s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
        cout << "YES" << endl;
        break;
      } else {
        cout << "NO" << endl;
        break;
      }
    }
  }
  return 0;
}
