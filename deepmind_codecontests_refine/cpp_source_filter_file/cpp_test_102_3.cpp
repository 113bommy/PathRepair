#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long lx = 1, rx = n, ly = 1, ry = m;
    long long x = 0, y = 0;
    pair<long long, long long> last = {1, 1};
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'R')
        ++y;
      else if (s[i] == 'L')
        --y;
      else if (s[i] == 'U')
        --x;
      else
        ++x;
      lx = max(lx, -x + 1);
      rx = min(rx, n - x);
      ly = max(ly, -y + 1);
      ry = min(ry, m - y);
      if (lx > rx || ly > ry) break;
      last = {lx, ly};
    }
    cout << last.first << " " << last.second << "\n";
  }
}
