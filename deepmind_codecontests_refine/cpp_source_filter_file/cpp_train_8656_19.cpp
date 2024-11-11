#include <bits/stdc++.h>
using namespace std;
void solve();
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long m = n++;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '8') {
      m = i;
      break;
    }
  }
  if (n - m >= 11)
    cout << "YES\n";
  else
    cout << "NO\n";
}
