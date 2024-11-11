#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int q = 0, e = 0;
  cin >> s;
  for (int i = 0; i < s.length() + 1; i++) {
    if (q == 7 || e == 7) {
      cout << "YES";
      return 0;
    }
    if (s[i] == '1') {
      q++;
      e = 0;
    } else if (s[i] == '0') {
      e++;
      q = 0;
    }
  }
  cout << "NO";
  return 0;
}
