#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, curr, res, i;
  cin >> t;
  while (t--) {
    curr = 0;
    res = 0;
    string s;
    cin >> s;
    n = s.length();
    for (i = 0; i < n; i++) {
      if (s[i] == '+')
        curr++;
      else
        curr--;
      if (i != (n - 1) && curr < 0) {
        res += (i + 1);
        curr++;
      } else if (i == (n - 1) && curr < 0) {
        res += (i + 1);
        break;
      } else if (i == (n - 1) && curr >= 0) {
        res += (i + 1);
        break;
      }
    }
    if (curr < 0) res += n;
    cout << res << endl;
  }
  return 0;
}
