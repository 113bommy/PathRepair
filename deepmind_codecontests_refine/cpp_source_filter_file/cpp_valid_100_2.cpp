#include <bits/stdc++.h>
using namespace std;
long long modInverse(long long a, long long b) {
  return 1 < a ? b - modInverse(b % a, a) * b / a : 1;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
const long long mod = 998244353;
long long fact[222222];
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long K = 0; K < n; K++) {
    cin >> a[K];
  };
  long long mx = 0;
  sort(a, a + n);
  mx = a[n - 1];
  if (a[n - 1] - a[n - 2] > 1) {
    cout << 0 << "\n";
    return;
  }
  long long cnt_small = 0;
  for (int k = 0; k < n; k++) {
    if (a[k] < mx - 1) cnt_small++;
  }
  long long ans = fact[n];
  if (a[0] == a[n - 1]) {
    cout << ans << "\n";
    return;
  }
  long long bad = 0;
  for (long long k = 0; k <= cnt_small; k++) {
    long long right =
        (fact[cnt_small] * modInverse(fact[cnt_small - k], mod)) % mod;
    bad = (bad + (right * fact[n - k - 1]) % mod) % mod;
  }
  ans = (ans - bad + mod) % mod;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  fact[0] = 1;
  for (long long k = 1; k < 222222; k++) {
    fact[k] = (k * fact[k - 1]) % mod;
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
