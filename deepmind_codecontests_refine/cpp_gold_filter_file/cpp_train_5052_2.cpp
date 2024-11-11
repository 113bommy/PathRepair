#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
  ll n, b;
  cin >> n >> b;
  vector<pair<ll, ll> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  ll now = 0;
  queue<pair<pair<ll, ll>, ll> > q;
  vector<ll> ans(n + 1);
  v.push_back({1e+18, 0});
  ++b;
  for (int i = 0; i < n + 1; ++i) {
    while (q.size() and
           v[i].first >= max(now + q.front().first.second,
                             q.front().first.first + q.front().first.second)) {
      now = max(now + q.front().first.second,
                q.front().first.first + q.front().first.second);
      ans[q.front().second] = now;
      q.pop();
    }
    if (q.size() < b) {
      q.push({v[i], i});
    } else {
      ans[i] = -1;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
