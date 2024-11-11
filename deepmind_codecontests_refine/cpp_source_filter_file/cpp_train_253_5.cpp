#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
  while (cin >> s) {
    int len = strlen(s), ct = 0, flag = 1;
    for (int i = len - 10; i >= 0; i--) {
      if (s[i] == '#')
        break;
      else if (s[i] == '(')
        ct++;
      else if (s[i] == ')')
        ct--;
      if (ct > 0) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      cout << "-1" << endl;
      continue;
    }
    int m = 0;
    ct = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '#') {
        s[i] = ')';
        m++;
      }
    }
    for (int i = 0; i < len; i++) {
      if (s[i] == '(')
        ct++;
      else
        ct--;
      if (ct < 0) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      cout << "-1" << endl;
      continue;
    }
    for (int i = 0; i < m - 1; i++) cout << '1' << endl;
    cout << 1 + ct << endl;
  }
  return 0;
}
