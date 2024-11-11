#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int x = s.length();
  for (int i = x; i >= 0; i--) {
    char c = tolower(s[i]);
    if (!(c >= 'a' && c <= 'z')) {
      continue;
    }
    if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
         c == 'y')) {
      cout << "YES" << endl;
      break;
    } else {
      cout << "NO" << endl;
      break;
    }
  }
  return 0;
}
