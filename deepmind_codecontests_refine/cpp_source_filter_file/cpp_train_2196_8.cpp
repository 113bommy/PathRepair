#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 1e18;
const ll mod = (1LL << 32);
const ll MOD = 998244353;
const ll MAX = 1e5 + 1;
inline ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
inline ll sub(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }
inline ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll pwr(ll x, ll n) {
  if (!n) return 1;
  if (n & 1)
    return mul(x, pwr(mul(x, x), (n - 1) / 2));
  else
    return pwr(mul(x, x), n / 2);
}
ll modinv(ll n) { return pwr(n, mod - 2); }
ll a, b, c, d, n, ans = 0;
vector<ll> primes;
ll f(ll x) { return add(d, mul(x, add(c, mul(x, add(b, mul(a, x)))))); }
void simpleSieve(ll limit, vector<ll> &prime) {
  bitset<MAX> mark;
  for (ll i = 0; i < limit + 1; i++) {
    mark[i] = 1;
  }
  for (int p = 2; p * p < limit; p++) {
    if (mark[p] == 1) {
      for (ll i = p * 2; i < limit; i += p) mark[i] = 0;
    }
  }
  for (int p = 2; p < limit; p++) {
    if (mark[p] == 1) {
      prime.push_back(p);
      ll x = n, sum = 0;
      while (x) {
        sum = add(sum, x / p);
        x /= p;
      }
      ans = add(ans, mul(f(p), sum));
    }
  }
}
void segmentedSieve(ll n) {
  ll limit = floor(sqrt(n)) + 1;
  vector<ll> prime;
  simpleSieve(limit, prime);
  ll low = limit;
  ll high = 2 * limit;
  bitset<MAX> mark;
  while (low < n) {
    if (high >= n) high = n;
    for (ll i = 0; i < limit + 1; i++) {
      mark[i] = 1;
    }
    for (ll i = 0; i < prime.size(); i++) {
      ll loLim = floor(low / prime[i]) * prime[i];
      if (loLim < low) loLim += prime[i];
      for (ll j = loLim; j < high; j += prime[i]) mark[j - low] = false;
    }
    for (ll i = low; i < high; i++) {
      if (mark[i - low] == 1) {
        ll x = n, sum = 0, p = i;
        while (x) {
          sum = add(sum, x / p);
          x /= p;
        }
        ans = add(ans, mul(f(p), sum));
      }
    }
    low = low + limit;
    high = high + limit;
  }
}
void speed_solve() {
  cin >> n >> a >> b >> c >> d;
  segmentedSieve(n + 1);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll test_cases = 1;
  for (ll i = 0; i < test_cases; i++) {
    speed_solve();
  }
  return 0;
}
