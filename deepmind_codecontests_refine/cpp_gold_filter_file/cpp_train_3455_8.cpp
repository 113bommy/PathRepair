#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << s << '\n';
    return;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (s[0] != '1') {
    s[0] = '1';
    k--;
  }
  if (k > 0) {
    for (long long int i = 1; i < n; i++) {
      if (k < 1) {
        break;
      }
      if (s[i] == '0') continue;
      s[i] = '0';
      k--;
    }
  }
  cout << s << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t = 1;
  while (t--) {
    solve();
  }
}
