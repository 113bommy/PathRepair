#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll SIZE = 4e5 + 100;
ll t[SIZE];
map<pair<int, int>, vector<int>> m;
void solve() {
  int n;
  cin >> n;
  ll all = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    all = all ^ t[i];
  }
  if (all == 0 && n % 2 == 0) {
    ans--;
  }
  int a = 0;
  set<pair<ll, ll>> g;
  for (int i = n - 1; i >= 0; i--) {
    a = a ^ t[i];
    m[{a, i & 1}].push_back(i);
    g.insert({a, i & 1});
    if (a == 0 && i % 2 != (n - 1) % 2) {
      ans++;
    }
  }
  for (auto p : g) {
    sort(m[p].begin(), m[p].end());
  }
  ll b = 0;
  for (int i = 0; i < n; i++) {
    b = b ^ t[i];
    ll w = b ^ all;
    if (i < n - 3) {
      int odd = !(i % 2);
      auto it = lower_bound(m[{w, odd}].begin(), m[{w, odd}].end(), i + 3);
      ans += (m[{w, odd}].end()) - it;
    }
    if (b == 0 && i % 2 == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
