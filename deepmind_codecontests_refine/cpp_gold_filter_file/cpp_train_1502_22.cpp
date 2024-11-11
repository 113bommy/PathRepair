#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string ss;
  cin >> ss;
  ll n = ss.size();
  map<char, ll> mp;
  for (int i = 0; i < n; ++i) {
    mp[ss[i]]++;
  }
  ll n1, n2, n3, ans = 0;
  cin >> n1 >> n2 >> n3;
  ll p1, p2, p3, r;
  if (mp['B'] == 0) p1 = n1 = 0;
  if (mp['S'] == 0) p2 = n2 = 0;
  if (mp['C'] == 0) p3 = n3 = 0;
  cin >> p1 >> p2 >> p3 >> r;
  ll s = 0, e = 1e15, md, an = 0;
  while (s <= e) {
    md = s + (e - s) / 2;
    ll cost = (max(mp['B'] * md - n1, 0ll)) * p1 +
              (max(mp['S'] * md - n2, 0ll)) * p2 +
              (max(mp['C'] * md - n3, 0ll)) * p3;
    if (cost <= r) {
      an = md;
      s = md + 1;
    } else
      e = md - 1;
  }
  ans += an;
  cout << ans << "\n";
  return 0;
}
