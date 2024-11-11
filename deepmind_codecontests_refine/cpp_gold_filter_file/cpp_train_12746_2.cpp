#include <bits/stdc++.h>
using namespace std;
bool use[1000];
string s, s2;
int main() {
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'O' &&
        s[i] != 'T' && s[i] != 'U' && s[i] != 'V' && s[i] != 'X' &&
        s[i] != 'Y' && s[i] != 'W' && s[i] != 'M') {
      cout << "NO";
      return 0;
    }
  }
  int l = 0, r = n - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      cout << "NO";
      return 0;
    }
    l++;
    r--;
  }
  cout << "YES";
  return 0;
}
