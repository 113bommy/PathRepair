#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l;
  string s, s1, s2;
  cin >> s;
  cin >> s1;
  l = s.length();
  s2 = "";
  for (int i = 0; i <= l; i++) {
    if (s[i] == s1[i]) {
      s2 += '0';
    } else {
      s2 += '1';
    }
  }
  cout << s2;
  return 0;
}
