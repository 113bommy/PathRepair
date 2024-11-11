#include <bits/stdc++.h>
using namespace std;
string s, m, n;
int i;
int main() {
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    n += s[i];
    if (s[i] != 'a') m += s[i];
    if (n.length() + m.length() == s.length()) break;
  }
  if (n + m == s)
    cout << n << endl;
  else
    cout << ":(" << endl;
}
