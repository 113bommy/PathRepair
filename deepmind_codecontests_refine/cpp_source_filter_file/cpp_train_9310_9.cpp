#include <bits/stdc++.h>
using namespace std;
string tt(string s) {
  int i, j, k, l = s.length();
  string t = "";
  t += s[0];
  for (i = 1; i < l; i++) {
    if (i + 3 < l && strncmp(s.c_str() + i, "dot", 3) == 0) {
      i += 2;
      t += '.';
    } else {
      t += s[i];
    }
  }
  return t;
}
int main() {
  string res, s, t;
  int i, j, k, l;
  for (i = 0; i < 1000; i++) res += 'z';
  cin >> s;
  l = s.length();
  for (i = 0; i < l; i++) {
    if (strncmp(s.c_str() + i, "at", 2) == 0) {
      t = "";
      for (j = 0; j < i; j++) {
        t += s[j];
      }
      t += '@';
      for (j = i + 2; j < l; j++) {
        t += s[j];
      }
      if (t[t.length() - 1] == '@') continue;
      res = min(res, tt(t));
    }
  }
  cout << res << endl;
  return 0;
}
