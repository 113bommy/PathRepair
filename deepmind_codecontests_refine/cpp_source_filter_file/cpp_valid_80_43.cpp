#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = n / 2; i < n; i++) {
    if (s[i] == '0') {
      cout << 1 << ' ' << (i + 1) << ' ' << 1 << ' ' << i << '\n';
      return;
    }
  }
  if (s[n / 2 - 1] == '0') {
    cout << n / 2 << ' ' << n << ' ' << n / 2 + 1 << n << ' ' << '\n';
  } else {
    cout << n / 2 << ' ' << n - 1 << ' ' << n / 2 + 1 << ' ' << n << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
