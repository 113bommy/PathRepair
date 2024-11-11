#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    priority_queue<pair<ll, ll>> d;
    for (ll i = 1, temp; i <= n; i++) {
      cin >> temp;
      d.emplace(temp, i);
    }
    vector<pair<ll, ll>> ans;
    auto t1 = d.top();
    d.pop();
    auto t2 = d.top();
    d.pop();
    while (t2.first != 0) {
      ans.emplace_back(t1.second, t2.second);
      d.emplace(t1.first - 1, t1.second);
      d.emplace(t2.first - 1, t2.second);
      t1 = d.top();
      d.pop();
      t2 = d.top();
      d.pop();
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }
}
