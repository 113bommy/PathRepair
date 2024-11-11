#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using dd = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll INFLL = (ll)2e18, MOD = 1e9 + 7;
const int INF = 0x6f6f6f6f;
vector<vector<ll>> adj;
vector<int> vis;
int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1},
    dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
inline ll mexp(ll x, ll n, ll m) {
  ll res = 1;
  while (n) {
    if (n & 1) res = (res * x) % m;
    n >>= 1;
    x = ((x % m) * (x % m)) % m;
  }
  return res;
}
inline bool ispow2(ll x) { return x && (!(x & (x - 1))); }
inline ll gcd(ll x, ll y) {
  pll p{x, y};
  while (p.second) p = {p.second, p.first % p.second};
  return p.first;
}
int main(void) {
  cout << fixed;
  cerr << fixed;
  cout << setprecision(10);
  cerr << setprecision(3);
  mt19937 genr(chrono::high_resolution_clock::now().time_since_epoch().count());
  ll n, k, p;
  cin >> n >> k >> p;
  vector<int> per(n), pos(k);
  for (int i = 0; i < n; ++i) cin >> per[i];
  for (int i = 0; i < k; ++i) cin >> pos[i];
  ll ans = INFLL;
  sort(pos.begin(), pos.end());
  sort(per.begin(), per.end());
  for (int i = 0; i < k - n; ++i) {
    ll temp = 0;
    for (int j = 0; j < n; ++j) {
      temp = max(temp, abs(pos[i + j] - per[j]) + abs(p - pos[i + j]));
    }
    ans = min(ans, temp);
  }
  cout << ans << '\n';
  return 0;
}
