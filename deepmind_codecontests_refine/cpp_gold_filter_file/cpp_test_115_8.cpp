#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
bool isok(vector<ll>& v, ll mid, ll h) {
  ll now = 0;
  int n = v.size();
  v.push_back(LLONG_MAX);
  for (int i = 0; i < n; i++) {
    if (v[i] + mid > v[i + 1])
      now += v[i + 1] - v[i];
    else
      now += mid;
  }
  v.pop_back();
  return now >= h;
}
void solve() {
  ll n, h;
  cin >> n >> h;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  ll l = 0, r = LLONG_MAX;
  while (l + 1 < r) {
    ll mid = l + (r - l) / 2;
    if (isok(v, mid, h))
      r = mid;
    else
      l = mid;
  }
  cout << r << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
