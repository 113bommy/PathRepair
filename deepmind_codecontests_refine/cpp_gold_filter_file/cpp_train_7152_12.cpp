#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.length() >= 3) {
    for (int i = 0; i < s.length() - 2; i++) {
      if (s[i] != '.' && s[i + 1] != '.' && s[i + 2] != '.') {
        if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  cout << "NO";
}
