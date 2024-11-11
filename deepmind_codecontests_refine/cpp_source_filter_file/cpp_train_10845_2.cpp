#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;
void solveCase() {
  int n;
  cin >> n;
  ll curr_r = 0;
  cin >> curr_r;
  vector<pair<ll, ll>> gain, loss;
  for (size_t i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (b >= 0)
      gain.push_back({a, b});
    else {
      a = max(a, -b);
      loss.push_back({a + b, b});
    }
  }
  sort(gain.begin(), gain.end());
  sort(loss.begin(), loss.end());
  ;
  for (auto &x : gain) {
    ll a = x.first, b = x.second;
    ;
    if (curr_r >= a) {
      curr_r += b;
    } else {
      cout << "NO\n";
      return;
    }
  };
  reverse(loss.begin(), loss.end());
  for (auto &x : loss) {
    ll a_b = x.first, b = x.second;
    ll a = a_b + b;
    ;
    if (curr_r >= a) {
      curr_r += b;
    } else {
      cout << "NO\n";
      return;
    }
    if (curr_r < 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; ++i) solveCase();
  return 0;
}
