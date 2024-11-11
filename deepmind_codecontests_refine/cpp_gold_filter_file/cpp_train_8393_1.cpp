#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pos[26], cur[26], i;
  string ch;
  string str;
  cin >> n;
  int flag = 0;
  for (i = 0; i < 26; i++) pos[i] = 1;
  int count = 26;
  int ans = 0;
  while (n--) {
    cin >> ch >> str;
    if (flag == 1) {
      if (ch[0] == '!') {
        ans++;
      } else if (ch[0] == '?') {
        if (pos[str[0] - 'a'] == 0) {
          ans++;
        }
      }
    } else {
      int m = str.length();
      if (ch[0] == '!') {
        for (i = 0; i < 26; i++) cur[i] = 0;
        for (i = 0; i < m; i++) cur[str[i] - 'a'] = 1;
        for (i = 0; i < 26; i++) {
          if (cur[i] == 0) {
            if (pos[i] == 1) count--;
            pos[i] = 0;
          }
        }
      } else {
        if (ch[0] == '.') {
          for (i = 0; i < m; i++) {
            if (pos[str[i] - 'a'] == 1) {
              count--;
              pos[str[i] - 'a'] = 0;
            }
          }
        } else {
          if (pos[str[0] - 'a'] == 1) {
            count--;
            pos[str[0] - 'a'] = 0;
          }
        }
      }
      if (count == 1 || count == 0) flag = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
