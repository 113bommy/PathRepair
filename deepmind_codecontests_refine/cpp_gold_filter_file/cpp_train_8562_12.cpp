#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  {
    getline(cin, s);
    int c1 = 0, out = 0;
    bool c = (s[0] == 'C');
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'C' && !c) {
        c = true;
        out++;
        c1 = 0;
      } else if (s[i] == 'P' && c) {
        c = false;
        out++;
        c1 = 0;
      }
      if (s[i] == 'C' && c) {
        c1++;
      } else if (s[i] == 'P' && !c) {
        c1++;
      }
      if (c1 > 5) out++, c1 = 1;
    }
    if (c1 != 0) out++;
    cout << out << endl;
  }
  return 0;
}
