#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long> >;
const long long NUM = 1000030;
const long long N = 10000000;
vector<long long> lp, sieve;
vector<long long> pr;
void primefactor();
long long binpow(long long a, long long b);
long long binpow(long long a, long long b, long long mod);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool comp(long long a, long long b);
long long inversemod(long long a, long long mod);
void calc_sieve();
long long getdp(long long a, vi& primefac) {
  long long val = 0;
  if (a % 2 == 0) {
    while (a % 2 == 0) a /= 2;
    val = max(val, primefac[2] + 1);
  }
  for (long long i = 3; i * i <= a; i++) {
    if (a % i == 0) {
      while (a % i == 0) a /= i;
      val = max(val, primefac[i] + 1);
    }
  }
  if (a > 1) val = max(val, primefac[a] + 1);
  return val;
}
void update(long long a, long long val, vi& primefac) {
  if (a % 2 == 0) {
    while (a % 2 == 0) a /= 2;
    primefac[2] = max(primefac[2], val);
  }
  for (long long i = 3; i * i <= a; i++) {
    if (a % i == 0) {
      while (a % i == 0) a /= i;
      primefac[i] = max(primefac[i], val);
    }
  }
  if (a > 1) primefac[a] = max(primefac[a], val);
}
void test() {
  long long n, i;
  cin >> n;
  vi arr(n);
  for (i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  vi dp(n), primefac(100001, 0);
  for (i = 0; i < n; i++) {
    dp[i] = getdp(arr[i], primefac);
    update(arr[i], dp[i], primefac);
  }
  long long maxval = -1;
  for (i = 0; i < n; i++) maxval = max(maxval, dp[i]);
  cout << maxval << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) test();
  return 0;
}
void calc_sieve() {
  sieve.resize(NUM + 1, 0);
  for (long long x = 2; x <= NUM; x++) {
    if (sieve[x]) continue;
    for (long long u = x; u <= NUM; u += x) {
      sieve[u] = x;
    }
  }
}
void primefactor() {
  lp.resize(N + 1, 0);
  for (long long i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (long long j = 0;
         j < (long long)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a / gcd(a, b)) * b); }
bool comp(long long a, long long b) { return a > b; }
long long inversemod(long long a, long long mod) {
  return binpow(a, mod - 2, mod);
}
