#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 1000005;
const ll mod = 998244353;
ll n, k[N], cnt[N];
ll ans, dil = 1;
vector<ll> m[N];
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if ((b & 1))
      b--, (res *= a) %= mod;
    else
      (a *= a) %= mod, b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    (dil *= k[i]) %= mod;
    int x;
    for (int j = 1; j <= k[i]; j++) {
      cin >> x;
      m[i].push_back(x);
      cnt[x]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k[i]; j++) {
      (ans +=
       ((dil * binpow(k[i], mod - 2)) % mod * (cnt[m[i][j - 1]])) % mod) %= mod;
    }
  }
  (dil *= (n * n) % mod) %= mod;
  ans = (ans * binpow(dil, mod - 2)) % mod;
  cout << ans;
  return 0;
}
