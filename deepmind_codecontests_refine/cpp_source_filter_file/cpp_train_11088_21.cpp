#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int p = s.length();
  int a = s[0] - 48;
  int ctr = 1;
  int maxum = 0;
  int ct = 1;
  int l = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] - 48 == 1 - a) {
      maxum = max(maxum, ct);
      if (ct == 2) l++;
      ct = 1;
      ctr++;
      a = 1 - a;
    } else {
      ct++;
    }
  }
  if (ct == 2) l++;
  maxum = max(maxum, ct);
  if (maxum > 2)
    cout << ctr + 2 << endl;
  else if (l == 1)
    cout << ctr + 1 << endl;
  else if (l == 2)
    cout << ctr + 2 << endl;
  else
    cout << ctr << endl;
  return 0;
}
