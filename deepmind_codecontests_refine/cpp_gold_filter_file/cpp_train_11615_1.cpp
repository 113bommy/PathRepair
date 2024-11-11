#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 12) {
    int d1 = (s[0] - 48) * 10 + s[1] - 48;
    if (d1 == 0) {
      s[1] = '1';
    } else if (d1 >= 13 && s[1] == '0')
      s[0] = '1';
    else if (d1 >= 13)
      s[0] = '0';
    int d2 = (s[3] - 48) * 10 + s[4] - 48;
    if (d2 >= 60) s[3] = '0';
    cout << s;
  } else {
    int d1 = (s[0] - 48) * 10 + s[1] - 48;
    if (d1 >= 24) s[0] = '1';
    int d2 = (s[3] - 48) * 10 + s[4] - 48;
    if (d2 >= 60) s[3] = '0';
    cout << s;
  }
  return 0;
}
