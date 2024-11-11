#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a = 0, i;
  char c;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u') {
      cout << s[i];
      a = 0;
      continue;
    }
    if (a == 0) c = s[i];
    a++;
    if (c != s[i]) c = '.';
    if (a == 3 && c == '.') {
      a = 1;
      c = s[i];
      cout << " ";
    }
    cout << s[i];
  }
}
