#include <bits/stdc++.h>
using ll = unsigned long long;
using namespace std;
vector<ll> v(15000000, 0);
ll bs(ll x, ll a, ll b) {
  if (a <= b) {
    ll mid = a + (b - a) / 2;
    if (v[mid] == x)
      return mid;
    else if (v[mid] < x)
      return bs(x, mid + 1, b);
    else
      return bs(x, a, mid - 1);
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a = 1;
  v[1] = 1;
  for (int i = 2; i < 15000000; ++i) v[i] = v[i - 1] + i;
  ll n;
  cin >> n;
  ll k = bs(n, 1, 15000000 - 1);
  ll ans = n - v[k];
  if (ans == 0) ans = k;
  cout << ans << endl;
  return 0;
}
