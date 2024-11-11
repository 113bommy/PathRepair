#include <bits/stdc++.h>
using namespace std;
int main() {
  bool wasStrong = false;
  bool was = false;
  string t = "";
  string s;
  while (getline(cin, s)) {
    int cur = 0;
    for (cur = 0; cur < s.size() && s[cur] == ' '; cur++)
      ;
    if (cur < s.size() && s[cur] == '#') {
      if (was) cout << endl;
      cout << s;
      wasStrong = true;
    } else {
      if (wasStrong) cout << endl;
      wasStrong = false;
      for (int i = 0; i < (s.size()); i++) {
        if (s[i] != ' ') {
          cout << s[i];
        }
      }
    }
    was = true;
  }
  cout.flush();
  return 0;
}
