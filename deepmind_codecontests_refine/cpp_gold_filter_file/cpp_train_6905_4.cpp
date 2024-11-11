#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  string s;
  bool f = false, first = true;
  while (getline(cin, s)) {
    first = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        first = false;
        if (s[i] != '#') {
          for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') cout << s[i];
          }
          f = true;
        } else {
          if (f) cout << endl;
          cout << s << endl;
          f = false;
        }
        break;
      }
    }
    if (first) f = true;
  }
  if (f) cout << endl;
  return 0;
}
