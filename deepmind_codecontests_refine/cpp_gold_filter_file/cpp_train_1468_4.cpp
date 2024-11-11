#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  string a = "aeiou";
  if (len == 1) {
    if (a.find(s) == -1 && (s[0] != 'n')) {
      cout << "NO";
      return 0;
    } else {
      cout << "YES";
      return 0;
    }
  } else {
    for (int i = 0; i < len; i++) {
      if (a.find(s[i]) == -1 && (s[i] != 'n')) {
        if (a.find(s[i + 1]) == -1) {
          cout << "NO";
          return 0;
        }
      }
    }
    cout << "YES";
  }
  return 0;
}
