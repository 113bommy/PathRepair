#include <bits/stdc++.h>
using namespace std;
long long cnt[100009];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, m, n, kt = 0, tm = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "*" + s;
    bool ok = true;
    for (i = k + 1; i <= n; i++) {
      if (s[i] == '?') {
        s[i] = s[i - k];
      } else if (s[i] != s[i - k] && s[i - k] != '?')
        ok = false;
    }
    for (i = n - k; i >= 1; i--) {
      if (s[i] == '?') {
        s[i] = s[i + k];
      } else if (s[i] != s[i + k] && s[i + k] != '?')
        ok = false;
    }
    for (i = 1; i <= k; i++) {
      if (s[i] == '1') kt++;
      if (s[i] == '?') tm++;
    }
    if (kt > k / 2) {
      ok = false;
    }
    if (kt < k / 2) {
      if (tm < (k / 2 - kt)) ok = false;
    }
    if (ok)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
