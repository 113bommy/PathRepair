#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
const long long MOD = 1e9 + 7;
long long arr[N];
long long n, m, k, x, y, i, j, a, b, c, d;
long long kase = 1;
void kkp() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
void time() {}
void solve() {
  string s, ss;
  cin >> s >> ss;
  long long k = 0;
  long long n = (long long)s.size() - 1, m = (long long)ss.size() - 1;
  while (n >= 0 && m >= 0) {
    if (s[n] == '1' && ss[m] == '1')
      break;
    else if (s[n] == '0' && ss[m] == '1') {
      k++;
      m++;
    }
    n--;
    m--;
  }
  cout << k << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  long long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
