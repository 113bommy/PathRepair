#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  T = 1;
  while (T--) {
    string t, s, s1, s2;
    cin >> t;
    s = t;
    int i, j, x, l, a;
    for (i = 0; i < t.length(); i++) {
      if (t[i] == 'a') a = i;
    }
    for (i = 0; i < t.length(); i++) {
      if (t[i] == 'a') {
        t.erase(i, 1);
        i--;
      }
    }
    l = t.length();
    s1 = t.substr(0, l / 2);
    s2 = t.substr(l / 2, l - l / 2);
    if (s1 == s2) {
      for (i = 0, j = 0; j < s1.length();) {
        if (s[i] != 'a') {
          i++;
          j++;
        } else
          i++;
      }
      while (s[i] == 'a') {
        i++;
      }
      if (i > a) {
        s1 = s.substr(0, i);
        cout << s1 << endl;
      } else
        cout << ":(\n";
    } else {
      cout << ":(\n";
    }
  }
  return 0;
}
