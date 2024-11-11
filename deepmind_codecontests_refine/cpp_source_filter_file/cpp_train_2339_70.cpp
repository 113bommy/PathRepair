#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  int f, m, s;
  f = a.size(), m = b.size(), s = c.size();
  if (f == 4 && m == 8 && s == 8 || f == 8 && m == 5 && s == 5 ||
      f == 5 && m == 4 && s == 4) {
    cout << "F";
  } else if (m == 4 && f == 8 && s == 8 || m == 8 && f == 5 && s == 5 ||
             m == 5 && f == 4 && s == 4) {
    cout << "M";
  } else if (s == 4 && f == 8 && m == 8 || s == 8 && m == 5 && f == 8 ||
             s == 5 && f == 4 && m == 4) {
    cout << "S";
  } else {
    cout << "?";
  }
  return 0;
}
