#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, e, t, i, c = 0, dn = 3, di = 1, dt = 1, de = 3;
  n = e = t = i = 0;
  string s;
  cin >> s;
  for (int j = 0; j < s.length(); j++) {
    if (s[j] == 'n') {
      n++;
    }
    if (s[j] == 'e') {
      e++;
    }
    if (s[j] == 'i') {
      i++;
    }
    if (s[j] == 't') {
      t++;
    }
  }
  c = e / de;
  if (i / di < c) {
    c = i / di;
  }
  if (t / dt < c) {
    c = t / dt;
  }
  if ((n - 1) / (dn - 1) < c) {
    c = (n - 1) / (dn - 1);
  }
  cout << c << endl;
}
