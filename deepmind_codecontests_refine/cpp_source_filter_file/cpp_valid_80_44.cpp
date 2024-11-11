#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  if (s[n - 1] == '0') {
    cout << 1 << " " << n << " " << 1 << " " << n - 1 << '\n';
  } else {
    long long idx = -1;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0') idx = i + 1;
    }
    if (idx == -1) {
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << '\n';
      return;
    }
    if (idx >= n / 2) {
      cout << 1 << " " << idx << " " << 1 << " " << idx - 1 << '\n';
    } else {
      cout << idx << " " << n << " " << idx + 1 << " " << n << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
