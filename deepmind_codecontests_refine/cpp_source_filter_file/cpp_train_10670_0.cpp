#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> as(n);
  for (auto&& a : as) cin >> a;
  ll kx = 1;
  for (int i = 0; i < k; ++i) kx *= x;
  vector<ll> or_front(n);
  or_front[0] = as[0];
  for (int i = 1; i < n; ++i) or_front[i] = as[i] | or_front[i - 1];
  vector<ll> or_back(n);
  or_back[n - 1] = as[n - 1];
  for (int i = n - 2; i >= 0; --i) or_back[i] = as[i] | or_back[i + 1];
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    const int front = i - 1 > 0 ? or_front[i - 1] : 0;
    const int back = i + 1 < n ? or_back[i + 1] : 0;
    ans = max(ans, front | back | (kx * as[i]));
  }
  cout << ans << endl;
  return 0;
}
