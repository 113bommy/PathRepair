#include <bits/stdc++.h>
using namespace std;
int main() {
  int num = 0, i, b = 0, c = 0, j = 0;
  string s;
  cin >> s;
  while (1) {
    if (s.size() == 1)
      break;
    else if (s[s.size() - 1] == '0')
      s.erase(s.size() - 1);
    else {
      for (i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
          s[i] = '1';
          break;
        } else
          s[i] = '0';
      }
    }
    b++;
  }
  if (s[0] == '0') b++;
  cout << b << endl;
}
