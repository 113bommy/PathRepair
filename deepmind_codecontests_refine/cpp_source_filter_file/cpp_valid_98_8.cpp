#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      cout << i - 1 << " " << i << "\n";
      return;
    }
  }
  cout << -1 << " " << -1 << "\n";
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
