#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  getline(cin, str);
  int _at = 0;
  for (int i = 1; i < str.length(); i++) {
    if (str[i] == 'a' && str[i + 1] == 't' && _at == 0) {
      _at = 1;
      str[i] = '@';
      str[i + 1] = '^';
    }
    if (str[i] == 'd' && str[i + 1] == 'o' && str[i + 2] == 't' &&
        i + 2 < str.length() - 1) {
      str[i] = '.';
      str[i + 1] = '^';
      str[i + 2] = '^';
    }
  }
  for (int i = 0; i <= str.length(); i++) {
    if (str[i] == '^')
      continue;
    else
      cout << str[i];
  }
  return 0;
}
