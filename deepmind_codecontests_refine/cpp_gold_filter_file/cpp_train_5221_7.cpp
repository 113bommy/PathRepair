#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll, ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll modpow(ll a, ll b, ll mod = (ll)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int DEBUG = 1;
const int mxn = 1501;
int n;
int a[mxn], b[mxn];
map<int, int> source;
map<int, int> dp[mxn];
void solve() {
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = i; j <= n - 1; j++) {
      x += a[j];
      (dp[j + 1][x]) = max((dp[j + 1][x]), (source[x] + 1));
    }
    for (pii pp : dp[i + 1])
      (source[pp.first]) = max((source[pp.first]), (pp.second));
  }
  int x = 0;
  for (pii pp : source)
    if (source[x] < pp.second) x = pp.first;
  cout << source[x] << endl;
  vector<pii> schedule;
  for (int i = 0; i < n; i++) {
    int j = i, y = a[j++];
    while (j < n && y != x) y += a[j++];
    if (y == x) schedule.push_back(pii(i, j));
  }
  auto cmp = [](pii a, pii b) { return a.second < b.second; };
  sort(begin(schedule), end(schedule), cmp);
  int i = 0;
  for (pii pp : schedule) {
    if (i <= pp.first) {
      cout << pp.first + 1 << " " << pp.second << endl;
      i = pp.second;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n) solve();
  return 0;
}
