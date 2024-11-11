#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  for (int i = s.length() - 1; i > 0; i--) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      s[i] = toupper(s[i]);
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
          s[i] == 'U' || s[i] == 'Y')
        cout << "YES";
      else
        cout << "NO";
      return 0;
    }
  }
  return 0;
}
