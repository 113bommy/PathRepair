#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll maxSize = 100007;
ll a[maxSize];
unordered_map<ll, ll> posToId;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    auto next = a[i];
    ll pos = 0;
    while (next > 0) {
      ll rest = a[i] % 2;
      if (rest == 1) {
        if (posToId.find(pos) == posToId.end()) {
          posToId.emplace(pos, i);
        } else {
          posToId[pos] = -1;
        }
      }
      ++pos;
      next = next / 2;
    }
  }
  ll start = 0;
  ll pos = -1;
  for (const auto& item : posToId) {
    if (item.second != -1 && item.first > pos) {
      pos = item.first;
      start = item.second;
    }
  }
  cout << a[start] << ' ';
  for (ll i = 0; i < start; ++i) cout << a[i] << ' ';
  for (ll i = start + 1; i < n; ++i) cout << a[i] << ' ';
}
