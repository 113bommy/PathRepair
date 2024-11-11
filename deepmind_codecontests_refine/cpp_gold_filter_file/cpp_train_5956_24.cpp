#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long MAX = 2e5 + 10;
vector<long long> fc(MAX), infc(MAX);
long long binary_expo(long long a, long long p) {
  if (p == 0) return 1;
  if (p == 1) return a;
  long long x = binary_expo(a, p / 2);
  (x *= x) %= MOD;
  if (p & 1) (x *= a) %= MOD;
  return x;
}
long long inv(long long a) { return binary_expo(a, MOD - 2); }
void init() {
  fc[0] = infc[0] = 1;
  for (long long i = 1; i < MAX; i++) {
    fc[i] = (fc[i - 1] * i) % MOD;
    infc[i] = inv(fc[i]);
  }
}
long long ncr(long long n, long long r) {
  long long res = (fc[n] * infc[n - r]) % MOD;
  (res *= infc[r]) %= MOD;
  return res;
}
long long solve(long long n, long long k) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long nans = 1;
    if (i & 1) {
      (nans *= binary_expo(2, i - 1)) %= MOD;
    } else {
      nans *= (((binary_expo(2, i) - ncr(i, i / 2)) % MOD) * inv(2)) % MOD;
      ((nans %= MOD) += MOD) %= MOD;
    }
    (nans *= (ncr(n, i) * binary_expo(k - 2, n - i)) % MOD) %= MOD;
    (ans += nans) %= MOD;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  long long n, k;
  cin >> n >> k;
  vector<long long> h(n, 0);
  for (long long i = 0; i < n; i++) {
    cin >> h[i];
  }
  long long pwk = 0;
  for (long long i = 0; i < n; i++) {
    if (h[i] == h[(i + 1) % n]) {
      pwk++;
    }
  }
  long long rst = n - pwk;
  long long ans = solve(rst, k);
  (ans *= binary_expo(k, pwk)) %= MOD;
  cout << ans << endl;
  return 0;
}
