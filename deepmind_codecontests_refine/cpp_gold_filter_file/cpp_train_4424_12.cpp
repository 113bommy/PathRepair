#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string cod = "CODEFORCES";
  if (s.length() < cod.length()) {
    cout << "NO\n";
    return 0;
  }
  if (s[0] == 'C') {
    int in = 0;
    while (in < cod.length() && in < s.length() && s[in] == cod[in]) in++;
    if (in == cod.length()) {
      cout << "YES\n";
      return 0;
    }
    int kin = cod.length() - 1;
    int kkin = s.length() - 1;
    while (cod[kin] == s[kkin]) {
      kkin--;
      kin--;
    }
    if (in > kin) {
      cout << "YES\n";
      return 0;
    }
  }
  for (int(a) = 0; (a) < (s.length()); (a)++) {
    if (s[a] == 'C') {
      int plu = 0;
      while (a + plu < s.length() && plu < cod.length() &&
             s[a + plu] == cod[plu])
        plu++;
      if (plu == cod.length() && a + plu == s.length()) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
