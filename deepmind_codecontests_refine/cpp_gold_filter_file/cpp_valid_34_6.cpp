#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long a, unsigned long long p,
                         unsigned long long mod = 1e9 + 7) {
  unsigned long long res = 1, run = p % mod;
  while (p > 0) {
    if (p & 1) {
      res = (res * run) % mod;
    }
    p = (p >> 1);
    run = (run * run) % mod;
  }
  return res;
}
unsigned long long inverse(unsigned long long a,
                           unsigned long long mod = 1e9 + 7) {
  return power(a, mod - 2, mod);
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void pre() {}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  long long ans = INT_MIN;
  for (long long i = max(1LL, n - 2 * k); i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      ans = max(ans, i * j - k * (a[i - 1] | a[j - 1]));
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  pre();
  while (t--) {
    solve();
  }
}
