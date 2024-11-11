#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0;
  string s;
  cin >> s;
  cout << s[0];
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'a' && s[i + 1] == 't' && a == 0 && i != s.size() - 1) {
      cout << '@';
      a = 1;
      i += 1;
    } else if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't' &&
               i != s.size() - 2) {
      cout << '.';
      i += 2;
    } else
      cout << s[i];
  }
  return 0;
}
