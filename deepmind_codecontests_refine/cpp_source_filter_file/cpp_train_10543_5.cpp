#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC optimize("Os")
using namespace std;
using ll = long long int;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vi = vector<int>;
const ll mod = (ll)(1e9) + 7LL;
const ll M = 998244353LL;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ld pi = acos(-1);
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }
ll P(ll B, ll power, ll modulo) {
  ll ans = 1LL;
  while (power > 0LL) {
    if (power % 2LL == 1LL) {
      ans = (ans * B) % modulo;
    }
    B = (B * B) % modulo;
    power /= 2LL;
  }
  return ans;
}
bool isPrime(ll n) {
  if (n <= 1LL) {
    return false;
  }
  if (n <= 3LL) {
    return true;
  }
  if (n % 2 == 0LL || n % 3 == 0LL) {
    return false;
  }
  for (ll i = 5LL; (i * i) <= n; i += 6LL) {
    if (n % i == 0LL || n % (i + 2LL) == 0LL) {
      return false;
    }
  }
  return true;
}
void vok() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
}
const int mxN = int(1e5) + 100;
bool comp(const array<int, 2> &a, const array<int, 2> &b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 2>> v;
  for (int i = 0; i < m; i++) {
    cout << "? " << 1 << " " << i + 1 << endl;
    int inp;
    cin >> inp;
    v.push_back({inp, i});
  }
  sort((v).begin(), (v).end(), comp);
  int ans = v[0][0];
  for (int i = 1; i < n; i++) {
    cout << "? " << i + 1 << " " << v[0][1] << endl;
    int inp;
    cin >> inp;
    ans = min(ans, inp);
  }
  cout << "! " << ans << endl;
}
int main() {
  vok();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
