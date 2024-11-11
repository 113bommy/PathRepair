#include <bits/stdc++.h>
using namespace std;
bool ispal(string s) {
  bool pal = true;
  for (int z = 0; z < s.size() / 2; z++) {
    if (s[z] != s[s.size() - 1 - z]) pal = false;
    break;
  }
  return pal;
}
int main() {
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << -1 << endl;
    } else if (s.size() == 2) {
      if (s[0] == s[1])
        cout << -1 << endl;
      else
        cout << s << endl;
    } else {
      bool pal = true;
      for (int z = 0; z < s.size() / 2; z++) {
        if (s[z] != s[s.size() - 1 - z]) pal = false;
        break;
      }
      bool fk = false;
      if (pal == false)
        cout << s << endl;
      else {
        string s1 = s;
        while (true) {
          next_permutation(s.begin(), s.end());
          if (!ispal(s))
            break;
          else if (s == s1) {
            cout << -1 << endl;
            fk = true;
            break;
          }
        }
        if (!fk) cout << s << endl;
      }
    }
  }
}
