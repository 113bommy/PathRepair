#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  getline(cin, t);
  int a, b, s, tmp = 0, *sur;
  sur = &a;
  for (const char x : t) {
    if (x == '+') {
      *sur = tmp;
      sur = &b;
      tmp = 0;
    } else if (x == '=') {
      *sur = tmp;
      tmp = 0;
    } else
      tmp++;
  }
  s = tmp;
  if (a + b + 2 == s) {
    a++;
    s--;
  } else if ((a + b - 2) == s) {
    a--;
    s++;
  }
  if (a == 0 && b > 1) {
    a++;
    b--;
  } else if (b == 0 && a > 1) {
    b++;
    a--;
  }
  if (a + b == s && min(a, b) > 0) {
    for (int _ = 0; _ < a + b + s; _++) {
      if (_ == a)
        cout << '+' << '|';
      else if (_ == a + b)
        cout << '=' << '|';
      else
        cout << '|';
    }
  } else
    cout << "Impossible";
}
