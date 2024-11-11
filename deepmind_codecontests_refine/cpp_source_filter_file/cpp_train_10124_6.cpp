#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string s;
    unsigned int c, oc = 200001, ini;
    cin >> s;
    int len = s.length();
    for (int i = 1, ini = 1, c = 1; i < len; i = ini + c, c = 1, ini = i) {
      while (i < len) {
        if (s[i] == s[i + 1]) {
          c++;
          i++;
        } else
          break;
      }
      if (i + 1 == len || i == len || i - 1 == len) {
        break;
      }
      if (s[ini] != s[ini - 1] && s[ini] != s[i + 1] &&
          s[ini - 1] != s[i + 1]) {
        if (c < oc) oc = c;
      }
    }
    if (oc == 20001)
      cout << "0\n";
    else
      cout << oc + 2 << "\n";
  }
  return 0;
}
