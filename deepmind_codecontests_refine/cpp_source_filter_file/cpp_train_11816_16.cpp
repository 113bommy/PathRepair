#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 10;
inline long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long mul(long long x, long long y) {
  x = (1LL * x * y) % mod;
  return x;
}
long long fact[200005] = {0};
long long inv[200005] = {0};
long long gcd_extended(long long a, long long b, long long *x, long long *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  long long x1;
  long long y1;
  long long gcd = gcd_extended(b, a % b, &x1, &y1);
  *x = y1;
  *y = x1 - (a / b) * (y1);
  return gcd;
}
long long mod_inverse(long long n, long long p) {
  long long x, y;
  long long gcd = gcd_extended(n, p, &x, &y);
  return (x + mod) % mod;
}
long long f(long long x, long long y, long long x1, long long y1) {
  long long n = x1 - x + y1 - y;
  long long k = x1 - x;
  return ((fact[n]) * ((inv[k] * inv[n - k]) % mod)) % mod;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  set<pair<int, int> > s;
  for (int i = 1; i <= n; i++) {
    int r, c;
    cin >> r >> c;
    s.insert(make_pair(r, c));
  }
  if (s.find(make_pair(1, 1)) != s.end() ||
      s.find(make_pair(h, w)) != s.end()) {
    cout << 0;
    return 0;
  }
  fact[0] = 1;
  for (int i = 1; i <= 100003; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  inv[100003] = mod_inverse(fact[100003], mod);
  for (int i = 100003 - 1; i >= 0; i--) {
    inv[i] = (inv[i + 1] * (i + 1)) % mod;
  }
  s.insert(make_pair(h, w));
  vector<pair<long long, long long> > v(s.begin(), s.end());
  long long dp[2005] = {0};
  for (int i = 0; i < v.size(); i++) {
    int x = v[i].first;
    int y = v[i].second;
    dp[i] = f(1, 1, x, y);
    for (int j = i - 1; j >= 0; j--) {
      int x1 = v[j].first;
      int y1 = v[j].second;
      if (x1 <= x && y1 <= y) {
        dp[i] = (dp[i] - (dp[j] * f(x1, y1, x, y) % mod) + mod) % mod;
      }
    }
  }
  cout << dp[v.size() - 1];
  return 0;
}
