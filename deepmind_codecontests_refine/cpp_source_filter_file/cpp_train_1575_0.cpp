#include <bits/stdc++.h>
template <typename T>
void printVector(const T& t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}
using namespace std;
using ll = long long;
const int mode = 0;
const ll mod = 998244353;
ll pow(ll base, ll exp) {
  ll res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
ll inv(ll n) { return pow(n, mod - 2); }
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (m == 1 && k > 0) {
    cout << "0\n";
    return;
  }
  vector<long long> fact(2001);
  vector<long long> finv(2001);
  fact[0] = 1LL;
  finv[0] = 1LL;
  for (ll i = 1; i <= 2000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    finv[i] = (finv[i - 1] * inv(i)) % mod;
  }
  auto C = [&](ll N, ll K) {
    ll ans = (fact[N] * finv[K]) % mod;
    return (ans * finv[N - K]) % mod;
  };
  ll ans = C(n - 1, k);
  ans = (ans * m) % mod;
  if (k > 0) {
    ans = (ans * pow(m - 1, k - 1)) % mod;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  if (mode == 0) {
    solve();
  } else {
    cin >> t;
    while (t--) {
      solve();
    }
  }
}
