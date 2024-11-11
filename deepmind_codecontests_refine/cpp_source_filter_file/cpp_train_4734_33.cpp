#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s, '?');
  int i = s.length() - 1;
  while (s[i] == 32) i--;
  if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'e' || s[i] == 'i' ||
      s[i] == 'i' || s[i] == 'o' || s[i] == 'o' || s[i] == 'u' || s[i] == 'u' ||
      s[i] == 'Y' || s[i] == 'y') {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
