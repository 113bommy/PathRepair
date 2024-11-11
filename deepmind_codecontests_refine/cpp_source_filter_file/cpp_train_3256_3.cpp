#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC optimization("O3")
using namespace std;
const unsigned long long mod = 1000000007;
const long long inf = ((1ll << 31ll) - 1ll);
const long long INF = (((1ll << 59ll) - 1ll) * 2ll) + 1ll;
const long double pi = acos(-1);
const long long MAXN = 1000000;
vector<bool> Criba(MAXN + 1);
vector<long long> primes;
void iniciar_criba() {
  for (long long i = 2; i <= MAXN; i += 2) Criba[i] = 2;
  primes.push_back(2);
  for (long long i = 3; i <= MAXN; i += 2) {
    if (!Criba[i]) {
      primes.push_back(i);
      Criba[i] = i;
      for (long long j = i * i; j <= MAXN; j += (2 * i))
        if (!Criba[j]) Criba[j] = i;
    }
  }
}
bool isprime(long long tupac) { return (Criba[tupac] == tupac); }
long long GCD(long long q, long long r) {
  if (r == 0) return q;
  return GCD(r, q % r);
}
long long LCM(long long q, long long r) { return q * (r / GCD(q, r)); }
long long qpow(long long b, long long e) {
  if (!e) return 1;
  if (e & 1) return qpow(b, e - 1) * b % mod;
  long long pwur = qpow(b, e >> 1);
  return pwur * pwur % mod;
}
long long InverM(long long a, long long b) {
  long long eso = a - (a / b) * b;
  if (eso == 0) return 0;
  long long ans = (1 - b * InverM(b, eso)) / eso;
  if (ans < 0) ans += b;
  return ans;
}
long long t, n, D, m, k, bL, bR;
long long fun(long long a) { return primes[a] * primes[a]; }
void problem() {
  cin >> n;
  if (n == 1) {
    cout << 1;
    return;
  }
  long long L = 0, R = primes.size() - 1;
  k = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
  k--;
  while (L + 1 < R) {
    long long mid = (L + R) / 2;
    if (fun(mid) <= n) {
      L = mid;
    } else {
      R = mid;
    }
  }
  cout << k - L + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(9);
  srand(time(NULL));
  iniciar_criba();
  cin >> t;
  while (t--) {
    problem();
    cout << '\n';
  }
  return 0;
}
