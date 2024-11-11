#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(ll a, ll b, ll n) {
  if (2 * a > b) {
    return (n / 2) * b + (n % 2) * a;
  } else {
    return n * a;
  }
}
int main() {
  ll n, a;
  vector<ll> v;
  cin >> n;
  vector<ll> prefch(n, 0);
  vector<ll> prefnech(n, 0);
  ll cnt1 = 0, cnt2 = 0;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
    if (i % 2 == 0) {
      cnt1 += a;
    } else {
      cnt2 += a;
    }
    prefch[i] = cnt1;
    prefnech[i] = cnt2;
  }
  ll cnt = 0;
  for (ll i = 1; i < n - 1; i++) {
    if (prefch[i - 1] + prefnech[n - 1] - prefnech[i] ==
        prefnech[i - 1] + prefch[n - 1] - prefch[i]) {
      cnt++;
    }
  }
  if (prefch[n - 2] == prefnech[n - 2]) {
    cnt++;
  }
  if (prefnech[n - 1] == prefch[n - 1] - v[0]) {
    cnt++;
  }
  cout << cnt;
  return 0;
}
