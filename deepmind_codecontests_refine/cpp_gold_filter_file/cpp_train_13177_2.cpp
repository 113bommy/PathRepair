#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fLL;
const double err = 1e-9;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
ll n, k;
set<ll> powers;
map<ll, ll> back;
ll pref[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  ll v = 1;
  powers.insert(k);
  powers.insert(1);
  if (abs(k) != 1)
    while (llabs(v) <= 1e15) v *= k, powers.insert(v);
  ll ans = 0;
  ll x;
  ll sum = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> x;
    sum += x;
    pref[i + 1] = sum;
  }
  back[0]++;
  for (int(i) = (1); (i) < (n + 1); (i)++) {
    for (auto a : powers) ans += back[pref[i] - a];
    back[pref[i]]++;
  }
  cout << ans << endl;
  return 0;
}
