#include <bits/stdc++.h>
using namespace std;
int check(string s, int n, int k) {
  for (int j = 0; j < k; j++) {
    char ch = 'X';
    int f = 1;
    for (int i = j; i < n; i += k) {
      if (s[i] != ch) {
        f = 0;
      }
    }
    if (f == 1) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string ans = "";
    cin >> s;
    int c = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'X') {
        ans += "1X12 ";
        c++;
        break;
      }
    }
    if (check(s, n, 6) == true) {
      ans += "2X6 ";
      c++;
    }
    if (check(s, n, 4) == true) {
      ans += "3X4 ";
      c++;
    }
    if (check(s, n, 3) == true) {
      ans += "4X3 ";
      c++;
    }
    if (check(s, n, 2) == true) {
      ans += "6X2 ";
      c++;
    }
    if (check(s, n, 1) == true) {
      ans += "12X1 ";
      c++;
    }
    cout << c << " " << ans << endl;
  }
  return 0;
}
