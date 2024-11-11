#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int verti = 0, hori = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      if (hori == 0) {
        cout << "4 3" << endl;
        hori = 1;
      } else {
        cout << "4 1" << endl;
        hori = 0;
      }
    } else {
      if (verti == 0) {
        cout << "1 1" << endl;
        verti = 1;
      } else {
        cout << "3 1" << endl;
        verti = 0;
      }
    }
  }
  return 0;
}
