#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  string buf = "";
  if (s.length() % 2 != 0) {
    for (int i = s.length() - 1; i > s.length() / 2; i--) buf += s[i];
  } else {
    for (int i = s.length() - 1; i >= s.length() / 2; i--) buf += s[i];
  }
  if (s.substr(0, s.length() / 2) == buf)
    return true;
  else
    return false;
}
int main() {
  string s, buf;
  cin >> s;
  buf = s;
  if (s.substr(0, s.length() / 2) == s.substr(s.length() / 2, s.length()))
    cout << s.substr(0, s.length() / 2) + "a" +
                s.substr(s.length() / 2, s.length());
  else {
    bool ok = true;
    for (int i = 0; i <= s.length(); i++) {
      for (char j = 'a'; j <= 'z'; j++) {
        s.insert(i, 1, j);
        if (check(s) && ok) {
          cout << s << endl;
          ok = false;
        }
        s = buf;
      }
      s = buf;
    }
    if (ok) cout << "NA";
  }
}
