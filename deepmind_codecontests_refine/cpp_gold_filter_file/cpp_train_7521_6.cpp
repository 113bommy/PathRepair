#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p) % p;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  string s = "", s1 = "", s2 = "";
  for (long long int i = 0; i < 100; i++) {
    s += 'a';
    s1 += 'b';
    s2 += 'a';
  }
  cout << s << "\n";
  for (long long int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (s[0] == 'a')
        s = s1;
      else
        s = s2;
    } else if (s[a[i]] == 'a') {
      s = s.substr(0, a[i]) + s1.substr(0, 100 - a[i]);
    } else {
      s = s.substr(0, a[i]) + s2.substr(0, 100 - a[i]);
    }
    cout << s << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
