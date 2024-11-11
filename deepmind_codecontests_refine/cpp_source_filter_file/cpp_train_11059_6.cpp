#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int m = 0, vt = 0;
    int len = s.length();
    for (int j = 0; j < len; j++)
      if (s[j] == 'R') {
        if (j + 1 - vt > m) m = j + 1;
        vt = j + 1;
      }
    cout << max(m, len + 1 - vt) << "\n";
  }
  return 0;
}
