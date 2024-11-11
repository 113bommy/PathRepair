#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  bool fix = true;
  string f;
  f.resize(x.length());
  if (isupper(f[0]))
    f[0] = x[0] + 'a' - 'A';
  else
    f[0] = x[0] - 'a' + 'A';
  for (int i = 1; i < x.length(); i++) {
    if (islower(x[i])) {
      fix = false;
      break;
    } else {
      f[i] = x[i] + 'a' - 'A';
    }
  }
  if (fix)
    cout << f;
  else
    cout << x;
}
