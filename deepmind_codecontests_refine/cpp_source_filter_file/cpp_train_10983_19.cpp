#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int small = 0, up = 0;
  for (char ch : s) {
    if (ch >= 65 && ch <= 90)
      up++;
    else
      small++;
  }
  if (small > up) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 65 && s[i] <= 90) s[i] = 'a' + (s[i] - 'A');
    }
  } else {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') s[i] = 'A' + (s[i] - 'a');
    }
  }
  cout << s << endl;
}
