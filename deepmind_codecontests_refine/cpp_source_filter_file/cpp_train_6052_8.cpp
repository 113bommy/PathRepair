#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int h_z, v_t;
  h_z = 0;
  v_t = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (h_z == 0) {
        h_z = 1;
        cout << "1"
             << " "
             << "1" << endl;
      } else {
        h_z = 0;
        cout << "1"
             << " "
             << "3" << endl;
      }
    } else {
      if (v_t == 0) {
        v_t = 1;
        cout << "3"
             << " "
             << "4" << endl;
      } else {
        v_t = 0;
        cout << "1"
             << " "
             << "4" << endl;
      }
    }
  }
}
