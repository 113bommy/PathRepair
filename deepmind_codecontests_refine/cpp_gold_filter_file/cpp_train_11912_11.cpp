#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int zc = 0, rem = 0;
  char h[4] = {'1', '6', '8', '9'};
  int t = 1;
  string perms[] = {"1869", "6189", "1689", "6198", "1698", "9168", "8196"};
  for (int j = 0; j < 4; ++j) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == h[j]) {
        s[i] = '0';
        break;
      }
    }
  }
  string s2 = "";
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '0') {
      s2 += s[i];
      if (rem != 0 && rem < 7) {
        rem = 10 * rem;
      }
      rem = (rem + (s[i] - '0')) % 7;
    } else {
      zc++;
    }
  }
  rem = rem % 7;
  rem = (10000 * rem) % 7;
  s2 += perms[(7 - rem) % 7];
  for (int i = 4; i < zc; ++i) s2 += '0';
  cout << s2 << endl;
  return 0;
}
