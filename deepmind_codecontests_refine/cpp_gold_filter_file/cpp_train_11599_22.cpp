#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 0; i < len;) {
    if (s[i] != '1') {
      cout << "NO" << endl;
      return 0;
    }
    if (i + 3 <= len) {
      if (s[i + 1] == '4' and s[i + 2] == '4') {
        i += 3;
      } else if (s[i + 1] == '4') {
        i += 2;
      } else
        ++i;
    } else if (i + 2 <= len) {
      if (s[i + 1] == '4') {
        i += 2;
      } else
        ++i;
    } else
      ++i;
  }
  cout << "YES" << endl;
  return 0;
}
