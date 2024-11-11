#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, inf = 1e18;
long long modpow(long long n, long long p, long long m) {
  long long ret = 1;
  while (p > 0) {
    if (p & 1) ret = (ret * n) % m;
    p >>= 1;
    n = (n * n) % m;
  }
  return ret;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    string ans = "YES";
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] == 'a') {
        if (s[n - i - 1] != 'a' && s[n - i - 1] != 'c') {
          ans = "NO";
          break;
        }
      } else if (s[i] == 'z') {
        if (s[n - i - 1] != 'z' && s[n - i - 1] != 'x') {
          ans = "NO";
          break;
        }
      } else {
        if ((int)s[n - i - 1] != (int)s[i] + 2 &&
            (int)s[n - i - 1] != (int)s[i] - 2 &&
            (int)s[n - i - 1] != (int)s[i]) {
          ans = "NO";
          break;
        }
      }
    }
    cout << ans << endl;
  }
}
