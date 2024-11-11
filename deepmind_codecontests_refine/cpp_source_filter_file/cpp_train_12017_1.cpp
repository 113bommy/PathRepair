#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, i, a = 0, b = 0, c = 0, z = 0;
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) {
    if (s[i] == '+')
      z = 1;
    else if (s[i] == '=')
      z = 2;
    else {
      if (z == 0)
        a++;
      else if (z == 1)
        b++;
      else if (z == 2)
        c++;
    }
  }
  if (a + b == c)
    cout << s << endl;
  else if (a + 1 + b == c - 1) {
    for (i = 0; i < a; i++) cout << '|';
    cout << "|+";
    for (i = 0; i < b; i++) cout << '|';
    cout << "=";
    for (i = 0; i < c - 1; i++) cout << '|';
  } else if (a - 1 + b == c + 1) {
    if (a - 1 > 1)
      a--;
    else
      b--;
    if (b == 0) {
      cout << "Impossible";
      return 0;
    }
    for (i = 0; i < a; i++) cout << '|';
    cout << "+";
    for (i = 0; i < b; i++) cout << '|';
    cout << "=|";
    for (i = 0; i < c; i++) cout << '|';
  } else
    cout << "Impossible";
  return 0;
}
