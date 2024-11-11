#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1000000007;
const ll M1 = 998244353;
using vl = vector<ll>;
using pll = pair<ll, ll>;
ll power(ll x, ll y) {
  if (y == 0) return 1;
  ll res = power(x, y / 2);
  res = (res * res);
  if (y & 1) res = (res * x);
  return res;
}
ll powermod(ll x, ll y, ll mod) {
  if (y == 0) return 1;
  ll res = powermod(x, y / 2, mod);
  res = (res * res) % mod;
  if (y & 1) res = (res * x) % mod;
  return res;
}
bool isPrime(ll n) {
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int h[(int)1e6 + 5];
void solve() {
  int n, m, x, y;
  cin >> n >> m;
  vector<pair<int, int>> rob, lig;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    rob.push_back({x, y});
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    lig.push_back({x, y});
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int va = lig[j].first - rob[i].first;
      if (va > 0) {
        h[va] = max(h[va], lig[j].second - rob[i].second + 1);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = (int)1e6 + 3; i >= 0; i--) {
    h[i] = max(h[i], h[i + 1]);
    ans = min(ans, i + h[i]);
  }
  cout << max(1, ans) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  for (int i = 1; i <= test; i++) {
    solve();
  }
  return 0;
}
