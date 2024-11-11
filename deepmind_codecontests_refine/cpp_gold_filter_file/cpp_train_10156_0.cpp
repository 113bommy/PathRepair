#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while (cin >> s) {
    int len = s.size();
    int temp = 0;
    if (len == 1) {
      if (s[0] == 'a')
        s[0] = 'z';
      else
        s[0]--;
    } else {
      int temp = 0;
      for (int i = 0; i < len; i++) {
        if (temp == 2 && s[i] == 'a') break;
        if (s[i] == 'a' && temp != 2) temp = 1;
        if (s[i] != 'a') {
          temp = 2;
          s[i]--;
        }
        if (s[i] == 'a' && temp == 1 && i == len - 1) s[i] = 'z';
      }
    }
    cout << s << endl;
  }
  return 0;
}
