#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.length(), c = 0;
  string a = "0000000", b = "1111111";
  for (int i = 0; i < l - 7; i++) {
    if (s.substr(i, 7) == a || s.substr(i, 7) == b) {
      cout << "YES" << endl;
      c = 1;
      break;
    }
  }
  if (c != 1) cout << "NO" << endl;
}
