#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
ll solve(vector<ll>& a, int index) {
  ll x = a[index];
  vector<pair<ll, ll> > div;
  for (ll i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      if (x != i * i) {
        div.push_back(make_pair(x / i, 0LL));
      }
      div.push_back(make_pair(i, 0LL));
    }
  }
  sort(div.begin(), div.end());
  const ll n = a.size();
  for (int i = 0; i < n; i++) {
    ll gcd_value = gcd(x, a[i]);
    auto div_pair =
        lower_bound(div.begin(), div.end(), make_pair(gcd_value, 0LL));
    div_pair->second++;
  }
  for (int i = 0; i < div.size(); i++) {
    for (int j = i + 1; j < div.size(); j++) {
      if (div[j].first % div[i].first == 0) {
        div[i].second += div[j].second;
      }
    }
  }
  for (int j = div.size() - 1; j >= 0; j--) {
    if (2 * div[j].second >= n) return (div[j].first);
  }
  return 0;
}
ll random_gen() {
  ll a = rand();
  ll b = rand();
  ll rmax = RAND_MAX;
  return a * (rmax + 1) + b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ll n;
  cin >> n;
  ll ans = 0;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 12; i++) {
    ll index = random_gen() % n;
    ll k = solve(a, index);
    ans = max(ans, k);
  }
  cout << ans << '\n';
  return 0;
}
