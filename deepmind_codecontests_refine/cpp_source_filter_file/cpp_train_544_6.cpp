#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, c0, c1;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    c0 = c1 == 0;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        c0++;
      }
    }
    c1 = s.length() - c0;
    if (min(c0, c1) & 1)
      cout << "DA"
           << "\n";
    else
      cout << "NET"
           << "\n";
  }
  return 0;
}
