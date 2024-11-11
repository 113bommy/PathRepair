#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int L = s.size();
  int x[L + 1], y[L + 1];
  x[0] = y[0] = 0;
  for (int i = 0; i <= L; ++i) {
    if (s[i] == 'L') {
      x[i + 1] = x[i] - 1;
      y[i + 1] = y[i];
    } else if (s[i] == 'R') {
      x[i + 1] = x[i] + 1;
      y[i + 1] = y[i];
    } else if (s[i] == 'U') {
      x[i + 1] = x[i];
      y[i + 1] = y[i] + 1;
    } else {
      x[i + 1] = x[i];
      y[i + 1] = y[i] - 1;
    }
  }
  bool found = false;
  for (int i = 0; i <= L && !found; ++i) {
    int a2 = a - x[i], b2 = b - y[i];
    if (x[L] == 0 && y[L] == 0) {
      if (a2 == 0 && b2 == 0) found = true;
    } else if (x[L] == 0) {
      if (a2 == 0 && b2 % y[L] == 0 && b2 / y[L] >= 0) found = true;
    } else if (y[L] == 0) {
      if (b2 == 0 && a2 % x[L] == 0 && a2 / x[L] >= 0) found = true;
    } else {
      if (a2 % x[L] == 0 && b2 % y[L] == 0 && a2 / x[L] == b2 / y[L] &&
          a2 / x[L] >= 0)
        found = true;
    }
  }
  cout << (found ? "YES" : "NO") << '\n';
  return 0;
}
