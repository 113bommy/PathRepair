#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  int l = s.length();
  while (!((s[l - 1] >= 65 && s[l - 1] <= 91) ||
           (s[l - 1] >= 96 && s[l - 1] <= 122))) {
    l--;
  }
  if (s[l - 1] == 'A' || s[l - 1] == 'E' || s[l - 1] == 'I' ||
      s[l - 1] == 'O' || s[l - 1] == 'U' || s[l - 1] == 'Y' ||
      s[l - 1] == 'a' || s[l - 1] == 'e' || s[l - 1] == 'i' ||
      s[l - 1] == 'o' || s[l - 1] == 'u' || s[l - 1] == 'y')
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
