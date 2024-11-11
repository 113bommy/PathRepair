#include <bits/stdc++.h>
using namespace std;
bool f = 0;
int m = 0;
string purify(string s) {
  bool t = 0, ok = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') continue;
    t++;
    if (s[i] == '#' && t == 1) {
      ok = 1;
      break;
    } else
      break;
  }
  string p = "";
  if (ok) {
    if (f) p += '\n';
    p += s;
    p += '\n';
    m = 1;
    return p;
  } else {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ' || s[i] == '\n') continue;
      p += s[i];
    }
    m = 2;
    return p;
  }
}
int main() {
  string s;
  while (getline(cin, s)) {
    cout << purify(s);
    f = 1;
  }
  if (m == 2) cout << "\n";
}
