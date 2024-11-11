#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using pill = pair<int, ll>;
using vvi = vector<vi>;
ll gcd(ll a, ll b) {
  ll t;
  while ((t = a % b) != 0) {
    a = b;
    b = t;
  }
  return b;
}
ll fast_exp(ll base, ll n, ll m) {
  if (n == 0) return 1;
  ll t = fast_exp(base, n / 2, m);
  if (n % 2 == 0)
    return (t * t) % m;
  else
    return (((t * t) % m) * base) % m;
}
bool is_set(int i, ll mask) { return (mask >> i) & 1; }
int count_bits(ll mask) {
  int ans = 0;
  for (int i = 0; i < 64; ++i)
    if (is_set(i, mask)) ++ans;
  return ans;
}
int first_bit(ll mask) {
  int i = 0;
  while (i < 64)
    if (is_set(i++, mask)) return i - 1;
  return -1;
}
int const N = 5e5;
ll a[N + 1];
bool primes[2 * N + 1];
ll p[2 * N + 1];
ll sum[2 * N + 1];
void init() {
  primes[0] = primes[1] = true;
  for (int i = 2; i * i <= 2 * N; ++i)
    if (not primes[i])
      for (int j = 2 * i; j <= 2 * N; j += i) primes[j] = true;
}
ll cnt(int l, int r) { return max(0ll, p[r] - p[l - 1]); }
int main() {
  ios::sync_with_stdio(false);
  ll n, x, y;
  cin >> n >> x >> y;
  init();
  bool ao = true;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], ++p[a[i]];
    if (a[i] > 1) ao = false;
  }
  for (ll i = 1; i <= 2 * N; ++i)
    sum[i] = sum[i - 1] + i * p[i], p[i] += p[i - 1];
  ll ans = LLONG_MAX;
  for (ll g = 2; g <= 2 * N; ++g) {
    if (primes[g]) continue;
    ll cost = 0;
    for (ll k = g; k <= 2 * N; k += g) {
      ll f = max(k - g, k - x / y - 1);
      cost +=
          cnt(k - g + 1, f) * x + (cnt(f + 1, k) * k - (sum[k] - sum[f])) * y;
    }
    ans = min(ans, cost);
  }
  cout << ans << "\n";
  return 0;
}
