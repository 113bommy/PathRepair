#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, h, k, t, res;
  string s;
  cin >> t;
  while (t--) {
    res = 0;
    cin >> n >> m >> h >> k;
    for (int i = 0; i < n; i++) {
      cin >> s;
      s += "*";
      for (int j = 0; j < s.length() - 1; j++) {
        if (s[j] == '*') continue;
        if (s[j] == s[j + 1] && 2 * h > k) {
          res += k;
          j++;
        } else
          res += h;
      }
    }
    cout << res << endl;
  }
  return 0;
}
