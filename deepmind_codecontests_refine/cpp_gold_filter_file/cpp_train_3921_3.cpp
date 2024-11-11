#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using vb = vector<bool>;
using vpi = vector<pi>;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
bool isprime(long long n) {
  if (n == 1) return false;
  if (n == 2) {
    return true;
  } else if (n % 2 == 0) {
    return false;
  } else {
    for (long long i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}
vector<long long> trial_division3(long long n) {
  vector<long long> factorization;
  for (long long d : {2, 3, 5}) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  static array<long long, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
  long long i = 0;
  for (long long d = 7; d * d <= n; d += increments[i++]) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
    if (i == 8) i = 0;
  }
  if (n > 1) factorization.push_back(n);
  return factorization;
}
void solve() {
  long long n, p;
  cin >> n >> p;
  vi a(n);
  for (long long i = (0); i <= (n - 1); ++i) cin >> a[i];
  vi pref(n);
  pref[0] = a[0];
  for (long long i = (1); i <= (n - 1); ++i) {
    pref[i] = pref[i - 1] + a[i];
  }
  long long sum = -INF;
  for (long long i = (1); i <= (n - 1); ++i) {
    long long lsum = (pref[i - 1]) % p;
    long long rsum = (pref[n - 1] - pref[i - 1]) % p;
    sum = max(sum, lsum + rsum);
  }
  cout << sum;
}
int32_t main() {
  long long t = 1;
  while (t--) solve();
  return 0;
}
