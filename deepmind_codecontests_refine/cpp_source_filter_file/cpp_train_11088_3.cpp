#include <bits/stdc++.h>
using namespace std;
int Calcul(string s) {
  char e;
  int r = 1;
  e = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (e != s[i]) {
      r++;
    }
    e = s[i];
  }
  return r;
}
int main() {
  int n, a;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1) {
    cout << 1;
  } else {
    if (n == 2) {
      cout << 2;
    }
    if (n > 2) {
      a = Calcul(s);
      if (a == n)
        cout << a;
      else if (a == n - 1)
        cout << a;
      else
        cout << a + 2;
    }
  }
  return 0;
}
