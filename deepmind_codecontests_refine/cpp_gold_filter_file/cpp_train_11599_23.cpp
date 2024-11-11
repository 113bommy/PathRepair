#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int z = 0;
  if (s[0] != '1')
    cout << "NO" << endl;
  else {
    for (int i = 1; i < s.size(); i++) {
      if ((s[i] == '1') || (s[i] == '4' && s[i - 1] == '1') ||
          (s[i] == '4' && s[i - 1] == '4' && s[i - 2] == '1'))
        continue;
      else {
        cout << "NO" << endl;
        z = 1;
        break;
      }
    }
    if (z == 0) cout << "YES" << endl;
  }
  return 0;
}
