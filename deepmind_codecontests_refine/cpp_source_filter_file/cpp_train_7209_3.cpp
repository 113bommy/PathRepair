#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = INT_MAX - 1;
vector<ll> firstFlower;
vector<ll> secondFlower;
void solve() {
  ll n, m;
  cin >> n >> m;
  firstFlower = vector<ll>(m);
  vector<pair<ll, ll>> allFlowers;
  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    firstFlower[i] = a;
    allFlowers.push_back({a, b});
  }
  ll cs[m];
  sort(firstFlower.begin(), firstFlower.end());
  if (n == 1) {
    cout << firstFlower[m - 1] << '\n';
    return;
  }
  cs[0] = firstFlower[0];
  for (ll i = 1; i < m; i++) {
    cs[i] = cs[i - 1] + firstFlower[i];
  }
  ll ans = 0;
  ans = cs[m - 1];
  ans -= (n < m ? cs[m - 1 - n] : 0);
  for (pair<ll, ll> p : allFlowers) {
    ll pos = upper_bound(firstFlower.begin(), firstFlower.end(), p.second) -
             firstFlower.begin();
    ll greater = pos;
    ll pos1 = m - 1;
    ll pos2 = max(greater, m - 1 - n);
    ll tempAns = p.first;
    tempAns += cs[pos1] - (pos2 == 0 ? 0 : cs[pos2 - 1]);
    ll used = pos1 - pos2 + 2;
    if (p.first > p.second) {
      used--;
      tempAns -= p.first;
    }
    tempAns += p.second * (n - used);
    ans = max(tempAns, ans);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
