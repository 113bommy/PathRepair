#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll N = 2e5 + 5, mod = 1e9 + 7;
const ll inf = 1e18;
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
ll power(ll x, ll p) {
  ll r = 1ll;
  x = x % mod;
  while (p > 0) {
    if (p & 1) r = (r * x) % mod;
    p = p >> 1;
    x = (x * x) % mod;
  }
  return r;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort((a).begin(), (a).end());
  int ans = 0;
  for (int i = 2; i <= 100; i++) {
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l < r) {
      if (a[l] + a[r] > i) {
        r--;
      }
      if (a[l] + a[r] < i) {
        l++;
      } else {
        cnt++;
        l++;
        r--;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, p;
  cin >> t;
  for (p = 1; p <= t; p++) {
    solve();
  }
  return 0;
}
