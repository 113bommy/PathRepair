#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 1; i < s.size(); i++) {
    s[i] = (char)min((int)s[i], (int)('9' - s[i] + '0'));
    if (i == 0 && s[i] == '0') s[i] = '9';
  }
  cout << s << endl;
}
