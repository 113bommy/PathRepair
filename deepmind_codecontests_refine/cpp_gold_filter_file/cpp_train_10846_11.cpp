#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  vector<vector<ll>> b(60);
  for (ll x : a) {
    int e = 0;
    for (ll i = x; ~i & 1; i >>= 1, e++)
      ;
    b[e].push_back(x);
  }
  int mx = max_element((b).begin(), (b).end(),
                       [](vector<ll> &x, vector<ll> &y) {
                         return int((x).size()) < int((y).size());
                       }) -
           b.begin();
  vector<ll> ans;
  for (int i = 0; i < 60; i++) {
    if (i == mx) continue;
    ans.insert(ans.end(), (b[i]).begin(), (b[i]).end());
  }
  cout << int((ans).size()) << '\n';
  for (ll x : ans) cout << x << ' ';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int tcs = 1;
  for (int tc = 1; tc <= tcs; tc++) {
    solve();
  }
}
