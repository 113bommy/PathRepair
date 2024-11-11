#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int v = 0;
  int h = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (v == 0) {
        cout << "1 1" << endl;
        v = 1;
      } else {
        cout << "3 1" << endl;
        v = 0;
      }
    } else {
      cout << (h + 1) % 4 << " " << 3 << endl;
      h++;
    }
  }
  return 0;
}
