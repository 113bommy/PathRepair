#include <bits/stdc++.h>
using namespace std;
int main() {
  int ip;
  char cp;
  string s;
  cin >> s;
  ip = s[1] - 48;
  cp = s[0];
  if ((ip == 1 || ip == 8) && (cp == 'a' || cp == 'h'))
    cout << 3 << endl;
  else if (((ip == 1 || ip == 8) && (cp >= 'b' || cp <= 'g')) ||
           ((ip >= 2 || ip >= 7) && (cp == 'a' || cp == 'h')))
    cout << 5 << endl;
  else
    cout << 8 << endl;
  return 0;
}
