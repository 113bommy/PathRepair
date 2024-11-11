#include <bits/stdc++.h>
using namespace std;
char c;
string s, s1 = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main() {
  cin >> c;
  cin >> s;
  if (c == 'R') {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < s1.size(); j++) {
        if (s[i] == s1[j]) {
          s[i] = s1[j - 1];
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < s1.size(); j++) {
        if (s[i] == s1[j]) {
          s[i] = s[j + 1];
          break;
        }
      }
    }
  }
  cout << s;
  return 0;
}
