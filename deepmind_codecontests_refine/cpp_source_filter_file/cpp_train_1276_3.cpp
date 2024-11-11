#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll call(ll i, ll j, string s, ll c) {
  if (i > j) return 0;
  if (i == j) {
    if (s[i] == c + 'a') return 0;
    return 1;
  }
  ll mid = (i + j) >> 1;
  ll a1 = 0, a2 = 0;
  for (ll x = 0; x <= mid; x++) {
    if (s[x] != 'a' + c) a1++;
  }
  for (ll x = mid + 1; x <= j; x++) {
    if (s[x] != 'a' + c) a2++;
  }
  return min(a2 + call(i, mid, s, c + 1), a1 + call(mid + 1, j, s, c + 1));
}
int main() {
  ll t = 1;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    cout << call(0, n - 1, s, 0) << endl;
  }
}
