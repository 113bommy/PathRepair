#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll n, k;
deque<pll> arr;
map<ll, ll> m;
int main() {
  cin >> n >> k;
  for (ll x, i = 0; i < n; ++i) {
    cin >> x;
    m[x]++;
  }
  for (auto& x : m) {
    arr.push_back(x);
  }
  while (arr.size() > 1) {
    pll& a = arr[0];
    pll& b = arr[1];
    pll& c = arr[arr.size() - 2];
    pll& d = arr.back();
    if (a.second < d.second) {
      ll cnt = a.second * (b.first - a.first);
      if (k >= cnt) {
        k -= cnt;
        b.second += a.second;
        arr.pop_front();
      } else {
        a.first += k / a.second;
        break;
      }
    } else {
      ll cnt = d.second * (d.first - c.first);
      if (k >= cnt) {
        k -= cnt;
        c.second += d.second;
        arr.pop_back();
      } else {
        d.first -= k / d.second;
        break;
      }
    }
  }
  cout << arr.back().first - arr.front().first;
  return 0;
}
