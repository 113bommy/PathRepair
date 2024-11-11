#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int i, f, s1, s2, s;
  cin >> a;
  for (i = 0; i < a.length(); i++) {
    if (a[i] == '=') {
      f = i;
      break;
    }
  }
  s1 = f;
  s2 = a.length() - f;
  if (s1 == s2) {
    cout << a;
    return 0;
  }
  s = s2 - s1;
  if (s < 0) s = -s;
  if (s >= 3 || s == 1) {
    cout << "Impossible";
    return 0;
  }
  if (s1 > s2) {
    for (i = 0; i < a.length(); i++) {
      if (a[i] == '+') {
        f = i;
        break;
      }
    }
    if (f >= 2) {
      a.erase(0, 1);
      cout << a << "|";
      return 0;
    }
    a.erase(f + 1, 1);
    cout << a << "|";
    return 0;
  }
  a.erase(a.length() - 1, 1);
  cout << "|" << a;
}
