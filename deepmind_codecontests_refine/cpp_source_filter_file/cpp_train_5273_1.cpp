#include <bits/stdc++.h>
using namespace std;
char func(char c) {
  if (c >= 'A' && c <= 'Z') c = tolower(c);
  if (c == 'o')
    c = '0';
  else if (c == 'l' || c == 'I')
    c = '1';
  return c;
}
int main() {
  string s;
  int n;
  cin >> s >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (str.size() != s.size()) continue;
    bool ok = true;
    for (int j = 0; j < s.size(); j++) {
      if (func(s[j]) != func(str[j])) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
