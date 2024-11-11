#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
  char c;
  cin >> c;
  string s1;
  cin >> s1;
  if (c == 'R') {
    for (int i = 0; i < s1.length(); i++) {
      int index = s.find(s1[i]);
      s1[i] = s[index - 1];
    }
  } else
    for (int i = 0; i < s1.length(); i++) {
      int index = s.find(s1[i]);
      s1[i] = s1[index + 1];
    }
  cout << s1;
  return 0;
}
