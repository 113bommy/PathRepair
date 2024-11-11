#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const vector<int> mods = {998244353, 1000000007, 1000000009};
const long long inf = 3e18;
const double pi = acos(-1.0);
const double eps = 0.0000001;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class... K>
using umap = unordered_map<K...>;
template <class... K>
using uset = unordered_set<K...>;
const int N = 100100;
const int M = 300100;
long long n, a[N], tt, g[M], inv[M], res;
long long pw(long long a, long long e) {
  long long r = 1;
  while (e) {
    if (e & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    e >>= 1;
  }
  return r;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin >> n;
  for (long long i = (0); i < (n); ++i) {
    cin >> a[i];
    tt += a[i];
  }
  if (tt == 1) {
    cout << "0\n";
    return 0;
  }
  for (long long i = (1); i < (M); ++i) inv[i] = pw(i, mod - 2);
  for (long long i = tt; i >= 1; i--) {
    g[i] = (g[i + 1] * (n - 1) % mod * (tt - i) % mod + tt * (n - 1) % mod) %
           mod * inv[i] % mod;
  }
  for (long long i = (1); i < (tt + 1); ++i) g[i] = (g[i] + g[i - 1]) % mod;
  res = (1 - n + mod) % mod * g[tt] % mod;
  for (long long i = (0); i < (n); ++i) res = (res + g[tt - a[i]]) % mod;
  res = res * inv[n] % mod;
  cout << res << "\n";
  return 0;
}
