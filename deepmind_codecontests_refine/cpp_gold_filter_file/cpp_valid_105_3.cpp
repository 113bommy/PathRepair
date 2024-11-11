#include <bits/stdc++.h>
using namespace std;
long long spf[101];
long long fac[101];
long long add(long long a, long long b) {
  if (a + b > 1000000007)
    return a + b - 1000000007;
  else
    return a + b;
}
long long sub(long long a, long long b) {
  if (a - b < 0)
    return a - b + 1000000007;
  else
    return a - b;
}
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < 101; i++) spf[i] = i;
  for (long long i = 4; i < 101; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 101; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 101; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
map<long long, long long> getfactor(long long a) {
  map<long long, long long> m;
  while (a > 1) {
    m[spf[a]]++;
    a /= spf[a];
  }
  return m;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0 || y < 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long inverse(long long a, long long p) { return power(a, p - 2, p); }
long long ncr(long long n, long long r, long long p) {
  if (r > n) return 0;
  if (r == 0 || r == n) return 1;
  return (fac[n] * inverse(fac[r], p) % p * inverse(fac[n - r], p) % p) % p;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v[n + 1];
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  long long dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (long long j = 1; j < n; j++) {
    for (long long i = 1; i <= n - j; i++) {
      if (a[i] == a[i + 1])
        dp[i][i + j] = dp[i + 1][i + j];
      else
        dp[i][i + j] = 1 + dp[i + 1][i + j];
      for (auto it : v[a[i]]) {
        if (it <= i + j && it > i + 1)
          dp[i][i + j] =
              min(dp[i][i + j], dp[it][i + j] + dp[i + 1][it - 1] + 1);
      }
    }
  }
  cout << dp[1][n] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
}
