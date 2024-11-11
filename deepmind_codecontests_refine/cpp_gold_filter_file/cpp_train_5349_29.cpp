#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l;
  l = int(s[0]);
  if (l >= 97 && l <= 122) {
    l = l - 32;
    s[0] = char(l);
  }
  cout << s;
  return 0;
}
