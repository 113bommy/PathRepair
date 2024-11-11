#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n - 2; i++) {
    if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
      s[i] = '1';
      s[i + 1] = '1';
      s[i + 2] = '1';
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != '1') {
      if (s[i + 1] = '1') {
        cout << s[i] << " ";
      } else {
        cout << s[i];
      }
    }
  }
  return 0;
}
