#include <bits/stdc++.h>
using namespace std;
bool check(char a, char b, char c) {
  return ((a - '0') * 100 + (b - '0') * 10 + (c - '0')) % 8 == 0;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' || s[i] == '8') {
      cout << "YES" << endl;
      cout << s[i] << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (check('0', s[i], s[j])) {
        cout << "YES" << endl;
        cout << s[i] << s[j] << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (check(s[i], s[j], s[k])) {
          cout << "YES" << endl;
          cout << s.substr(0, i + 1) << s[j] << s[k] << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
