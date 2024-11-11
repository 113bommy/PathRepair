#include <bits/stdc++.h>
using namespace std;
int main() {
  int q = 0;
  bool bl = false;
  string s, h;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    h = "";
    while (s[i] != '>') {
      h += s[i];
      i++;
    }
    h += s[i];
    q++;
    bl = false;
    for (int j = 0; j < h.length(); j++) {
      if (h[j] == '/') {
        bl = true;
        break;
      }
    }
    if (bl == false) {
      for (int i = 1; i < q; i++) {
        cout << "  ";
      }
      cout << h << endl;
    }
    if (bl == true) {
      q -= 2;
      for (int i = 0; i < q; i++) {
        cout << "  ";
      }
      cout << h << endl;
    }
  }
}
