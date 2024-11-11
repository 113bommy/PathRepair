#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 9;
const long long MAX_SIZE = 1e7 + 1;
long long dx[4] = {0, -1, 1, 0}, dy[4] = {1, 0, 0, -1};
long long _t = 1, _T;
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long mmi(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long nxor(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
long long sum(long long n) { return ((n * (n + 1)) / 2); }
long long modsum(long long n, long long m) {
  long long ans = n % m;
  ans *= (n + 1) % m;
  ans %= m;
  ans *= mmi(2, m);
  return ans % m;
}
long long leap(long long y) {
  if (y % 400 == 0)
    return 1;
  else if (y % 100 == 0)
    return 0;
  else if (y % 4 == 0)
    return 1;
  else
    return 0;
}
long long mypow(long long x, long long n) {
  long long nn = n, ans = 1;
  while (nn) {
    if (nn % 2)
      ans *= x, nn--;
    else
      x *= x, nn /= 2;
  }
  return ans;
}
long long modpow(long long x, long long n, long long md) {
  long long nn = n, ans = 1;
  while (nn) {
    if (nn % 2)
      ans *= x, ans %= md, nn--;
    else
      x *= x, x %= md, nn /= 2;
  }
  return ans;
}
void solve(long long csn);
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  bool multicases = 1;
  if (multicases) cin >> _t;
  _T = _t;
  while (_t--) solve(_T - _t);
  return 0;
}
void solve(long long csn) {
  long long n;
  cin >> n;
  ;
  string s1, s2;
  cin >> s1 >> s2;
  long long ans = 0, i = 0;
  while (i < n) {
    if (s1[i] != s2[i]) {
      ans += 2;
      i++;
    } else if (s1[i] == '1') {
      if (i == n - 1)
        break;
      else if (s1[i + 1] == '0' || s2[i + 1] == '0') {
        ans += 2;
        i += 2;
      } else
        i++;
    } else {
      if (i == n - 1) {
        ans++;
        break;
      } else if (s1[i + 1] == '1' && s2[i + 1] == '1') {
        ans += 2;
        i += 2;
      } else {
        ans++;
        i++;
      }
    }
  }
  cout << ans << "\n";
  return;
}
