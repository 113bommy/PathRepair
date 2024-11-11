#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
signed main() {
  long long t, n, x, m, M = 1000, a, b, c = 0;
  string s;
  cin >> s;
  if (s.length() < 2) {
    cout << 0 << endl;
    return 0;
  }
  while (m >= 10) {
    m = 0;
    for (int i = 0; i < s.length(); i++) {
      m += s[i] - '0';
    }
    s = to_string(m);
    c++;
  }
  cout << c << endl;
  return 0;
}
