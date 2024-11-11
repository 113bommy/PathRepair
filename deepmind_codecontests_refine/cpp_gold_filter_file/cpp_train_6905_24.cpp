#include <bits/stdc++.h>
using namespace std;
string s, t;
int main() {
  bool you = 0;
  while (getline(cin, s)) {
    int i = 0;
    for (; i < s.length(); i++)
      if (s[i] != ' ') break;
    if (s[i] == '#') {
      if (you) {
        for (int i = 0; i < t.length(); i++)
          if (t[i] != ' ') cout << t[i];
        cout << endl;
        t.clear();
        you = 0;
      }
      cout << s << endl;
    } else {
      you = 1;
      t += s;
    }
  }
  if (you) {
    for (int i = 0; i < t.length(); i++)
      if (t[i] != ' ') cout << t[i];
    cout << endl;
  }
  return 0;
}
