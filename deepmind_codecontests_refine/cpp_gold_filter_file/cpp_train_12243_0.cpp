#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int x, y;
  cin >> s;
  x = 10 * (s[1] - '0') + (s[0] - '0');
  y = 10 * (s[3] - '0') + (s[4] - '0');
  int z = 60 - y;
  if (s[0] == s[4] && s[1] == s[3])
    cout << "0";
  else if (x > y && x < 60)
    cout << x - y;
  else if (s[0] == '2' && s[1] == '3' && y > 32)
    cout << z;
  else if (s[0] == '0' && (s[1] - '0') >= 6)
    cout << 600 - (s[1] - '0') * 60 - y + 1;
  else if (s[0] == '1' && (s[1] - '0') >= 6)
    cout << 600 - (s[1] - '0') * 60 - y + 2;
  else if (s[0] == '0' && (s[1] - '0') == 5 && x < y)
    cout << 600 - (s[1] - '0') * 60 - y + 1;
  else if (s[0] == '1' && (s[1] - '0') == 5 && x < y)
    cout << 600 - (s[1] - '0') * 60 - y + 2;
  else if (x < y)
    cout << x + 10 + z;
  return 0;
}
