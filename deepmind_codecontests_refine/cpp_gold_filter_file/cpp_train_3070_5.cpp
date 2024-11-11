#include <bits/stdc++.h>
using namespace std;
int main() {
  int counter = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[i]) counter++;
  }
  if ((s.size() - counter) & 1)
    cout << "impossible\n";
  else {
    int take = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == t[i]) {
        if (s[i] == '0')
          cout << "1";
        else
          cout << "0";
      } else if (s[i] != t[i] && take == 0) {
        if (s[i] == '0')
          cout << "1";
        else
          cout << "0";
        take ^= 1;
      } else if (s[i] != t[i] && take == 1) {
        if (t[i] == '0')
          cout << "1";
        else
          cout << "0";
        take ^= 1;
      }
    }
    cout << endl;
  }
  return 0;
}
