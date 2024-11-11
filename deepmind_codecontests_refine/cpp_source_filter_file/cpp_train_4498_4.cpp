#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int maxn = 2e5 + 5;
int n, k;
int a[maxn];
int den, cnt;
ll der[maxn], ans;
ll f[maxn], inv[maxn];
ll binmod(ll a, ll b) {
  if (b == 0) return 1;
  ll x = binmod(a * a % mod, b >> 1);
  return b & 1 ? x * a % mod : x;
}
ll C(int a, int b) {
  if (a < b) return 0;
  return (((f[a] * inv[b]) % mod) * inv[a - b]) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (k == 1) return cout << 0, 0;
  if (n == 1) return cout << 1, 0;
  f[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * i) % mod;
  inv[n] = binmod(f[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;
  for (int i = 1; i <= n; i++) {
    int ind = i % n + 1;
    if (a[i] == a[ind])
      den++;
    else
      cnt++;
  }
  ll w = binmod(k, den);
  der[0] = 1;
  for (int i = 1; i <= n; i++) der[i] = (der[i - 1] * 2) % mod;
  for (int i = 0; i < cnt; i++) {
    int lft = cnt - i;
    ll way = der[lft];
    if (lft % 2 == 0) {
      way -= C(lft, lft / 2);
      if (way < 0) way += mod;
    }
    way = (way * inv[2]) % mod;
    ll nw = (binmod(k - 2, i) * C(cnt, i)) % mod;
    nw = (nw * way) % mod;
    ans = (ans + nw);
  }
  ans = (ans * w) % mod;
  cout << ans;
}
