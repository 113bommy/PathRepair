#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int fv = 0, fh = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (!fv) {
        cout << "1 4" << endl;
      } else
        cout << "3 4" << endl;
      fv = fv ^ 1;
    } else {
      if (!fh)
        cout << "4 1" << endl;
      else
        cout << "4 3" << endl;
      fh = fh ^ 1;
    }
  }
}
