#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h;
  string s;
  cin >> n >> s;
  m = (s[3] - '0') * 10 + s[4] - '0';
  if (m > 59) {
    s[3] = '0';
  }
  if (n == 24) {
    h = (s[0] - '0') * 10 + s[1] - '0';
    if (h > 23) {
      if (s[0] - '0' > 2)
        s[0] = '0';
      else if (s[1] - '0' > 3)
        s[1] = '0';
    }
  } else {
    h = (s[0] - '0') * 10 + s[1] - '0';
    if (h == 0) s[1] = '1';
    if (h > 12) {
      if (s[0] - '0' > 1)
        s[0] = '0';
      else if (s[1] - '0' > 2)
        s[1] = '2';
      if (s[0] == '0' && s[1] == '0') s[1] = '1';
    }
  }
  cout << s << endl;
  return 0;
}
