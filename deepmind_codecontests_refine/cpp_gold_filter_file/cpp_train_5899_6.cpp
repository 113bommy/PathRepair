#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int flag_1 = 0, flag_2 = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'b') flag_1 = 1;
    if (flag_1 == 1 && s[i] == 'a') {
      cout << "NO" << endl;
      return 0;
    }
    if (s[i] == 'c') flag_2 = 1;
    if (flag_2 == 1 && (s[i] == 'a' || s[i] == 'b')) {
      cout << "NO" << endl;
      return 0;
    }
  }
  int ca = 0, cb = 0, cc = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a')
      ca++;
    else if (s[i] == 'b')
      cb++;
    else
      cc++;
  }
  if (ca >= 1 && cb >= 1) {
    if (cc == ca || cc == cb)
      cout << "YES";
    else
      cout << "NO";
  } else
    cout << "NO";
  return 0;
}
