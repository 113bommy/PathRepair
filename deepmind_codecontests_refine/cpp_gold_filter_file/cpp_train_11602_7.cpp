#include <bits/stdc++.h>
using namespace std;
char m[1000000];
int main() {
  int t, i, j;
  string s;
  cin >> t;
  cin >> s;
  int l = s.length();
  for (i = 0; i < l; i++) m[i] = s[i];
  for (i = 1; i < t; i++) {
    cin >> s;
    for (j = 0; j < l; j++) {
      if (m[j] == '?') m[j] = s[j];
      if (m[j] != s[j] && s[j] != '?') m[j] = '!';
    }
  }
  for (i = 0; i < l; i++) {
    if (m[i] == '?')
      cout << 'x';
    else if (m[i] == '!')
      cout << '?';
    else
      cout << m[i];
  }
  return 0;
}
