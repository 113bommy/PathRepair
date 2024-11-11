#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  bool ver = false, hor = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (!ver) {
        cout << 3 << " " << 1 << endl;
        ver = true;
      } else {
        cout << 1 << " " << 1 << endl;
        ver = false;
      }
    } else {
      if (!hor) {
        cout << 1 << " " << 3 << endl;
        hor = true;
      } else {
        cout << 1 << " " << 1 << endl;
        hor = false;
      }
    }
  }
}
