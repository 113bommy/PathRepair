#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    long long n, m;
    cin >> n;
    m = n - 2;
    string s, t;
    bool ok = 1;
    for (long long i = 0; i < m; i++) {
      cin >> t;
      if (!i) {
        s += t;
      } else {
        long long sz = s.size();
        if (t[0] == s.back())
          s += t[1];
        else
          s += t, ok = 0;
      }
    }
    cout << s;
    if (ok) cout << 'a';
    cout << "\n";
  }
}
