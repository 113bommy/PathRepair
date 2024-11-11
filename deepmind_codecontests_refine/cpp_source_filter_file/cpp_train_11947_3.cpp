#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, p;
  cin >> n >> p;
  string s, t;
  cin >> s;
  for (i = 0; i < s.length() - p; i++) {
    if (s[i] != s[i + p] || s[i] != '.') break;
  }
  if (i == s.length() - p) {
    cout << "No";
    return 0;
  }
  for (i = 0; i < s.length() - p; i++) {
    if (s[i] == '.' && s[i + p] == '.') {
      s[i] = '1';
      s[i + p] = '0';
    } else if (s[i] == '.') {
      int temp = s[i + p] - '0';
      temp = 1 - temp;
      s[i] = temp + '0';
    } else if (s[i + p] == '.') {
      int temp = s[i] - '0';
      temp = 1 - temp;
      s[i + p] = temp + '0';
    }
  }
  for (i = 0; i < s.length(); i++)
    if (s[i] == '.') s[i] = '1';
  cout << s;
  return 0;
}
