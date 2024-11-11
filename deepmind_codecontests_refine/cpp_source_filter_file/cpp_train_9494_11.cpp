#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, r, p, s, win = 0;
    char ch;
    cin >> n;
    cin >> r >> p >> s;
    char ans[n + 5];
    for (long long i = 1; i <= n; i++) {
      cin >> ch;
      ans[i] = 'z';
      if (ch == 'S' && r > 0) {
        ans[i] = 'R';
        r--;
        win++;
      }
      if (ch == 'R' && p > 0) {
        ans[i] = 'P';
        p--;
        win++;
      }
      if (ch == 'P' && s > 0) {
        ans[i] = 'S';
        s--;
        win++;
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (ans[i] == 'z') {
        if (p > 0)
          ans[i] = 'P', p--;
        else if (r > 0)
          ans[i] = 'R', r--;
        else
          ans[i] = 'S';
      }
    }
    if (2 * win >= n) {
      cout << "YES\n";
      for (long long i = 1; i <= n; i++) cout << ans[i];
      cout << '\n';
    } else {
      cout << "YES\n";
    }
  }
}
