#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  int j = s.length() - 1;
  if (s.length() == 1) {
    if (s[i] == 'A' || s[i] == 'H' || s[i] == 'I' || s[i] == 'M' ||
        s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' ||
        s[i] == 'W' || s[i] == 'X' || s[i] == 'Y')
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    while (i <= j) {
      if ((s[i] == 'A' || s[i] == 'H' || s[i] == 'I' || s[i] == 'M' ||
           s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' ||
           s[i] == 'W' || s[i] == 'X' || s[i] == 'Y') &&
          (s[i] == s[j])) {
        i++;
        j--;
      } else {
        cout << "NO" << endl;
        break;
      }
    }
    if (i > j) cout << "YES" << endl;
  }
  return 0;
}
