#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[2000001];
bool is_prime[2000001];
void seive(long long N) {
  for (long long i = 0; i < N; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i * i <= N; i++) {
    if (is_prime[i] == true) {
      for (long long j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
void solve() {
  long long n, l, r, x;
  cin >> n >> l >> r >> x;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long cnt = 0;
  for (long long mask = 1; mask <= (1 << n); mask++) {
    if (mask & (mask - 1)) {
      long long mx = 0;
      long long mi = INT_MIN;
      long long ans = 0;
      for (long long i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          ans += a[i];
          mi = min(mi, a[i]);
          mx = max(mx, a[i]);
        }
      }
      if (ans >= l && ans <= r && (mx - mi) >= x) cnt++;
    }
  }
  cout << cnt << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
  return 0;
}
