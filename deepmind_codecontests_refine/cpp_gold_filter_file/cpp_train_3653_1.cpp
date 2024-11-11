#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, x;
  cin >> b >> a >> x;
  int n = a + b;
  string s = "";
  bool chkr = 0;
  if (a > b) chkr = 1;
  x++;
  while (x--) {
    if (chkr)
      s += '1', a--;
    else
      s += '0', b--;
    chkr ^= 1;
  }
  string s1 = "";
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == '1') {
      while (a) s1 += '1', a--;
    } else {
      while (b) s1 += '0', b--;
    }
    s1 += s[i];
  }
  cout << s1;
  return 0;
}
