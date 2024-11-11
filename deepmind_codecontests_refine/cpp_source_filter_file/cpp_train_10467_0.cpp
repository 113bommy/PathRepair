#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.length();
  cout << s;
  while (l >= 0) {
    cout << s[l - 1];
    l--;
  }
  return 0;
}
