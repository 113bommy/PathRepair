#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  for (int i = (s.length() - 1); i >= 0; i--) {
    if (isalpha(s[i])) {
      s[i] = tolower(s[i]);
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == 'y')
        cout << "Yes";
      else
        cout << "No";
      return 0;
    }
  }
  return 0;
}
