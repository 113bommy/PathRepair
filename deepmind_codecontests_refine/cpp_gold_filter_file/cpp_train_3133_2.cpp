#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n1, n2, i, n, z, o;
  n1 = s.length();
  n2 = t.length();
  n = min(n1, n2);
  z = 0;
  for (i = 0; i <= n - 1; i++) {
    if (s[n1 - 1 - i] == t[n2 - 1 - i])
      z++;
    else
      break;
  }
  o = n1 + n2 - z * 2;
  cout << o;
}
