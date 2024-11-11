#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using C = complex<double>;
const double PI = 3.14159265;
const double eps = 1e-8;
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e9 + 7;
const ll INF = 1e18;
ll pw(ll a, ll b) {
  ll t = 1;
  a %= M;
  for (; b; b >>= 1) {
    if (b & 1) {
      t = t * a % M;
    }
    a = a * a % M;
  }
  return t;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n, m, k, t;
int a[N];
vector<pii> g[N];
ll s[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> t;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> L(k), R(k), D(k);
  for (int i = 0; i < k; i++) {
    cin >> L[i] >> R[i] >> D[i];
  }
  t -= m + 1;
  int l = 0, r = n - 1, p, ans;
  while (l <= r) {
    p = l + r >> 1;
    vector<pii> seg;
    for (int i = 0; i < k; i++) {
      if (D[i] > a[p]) {
        seg.push_back({L[i], R[i]});
      }
    }
    int sum = 0;
    sort(seg.begin(), seg.end());
    pii ls = {1, 0};
    for (const pii& x : seg) {
      if (x.first > ls.second) {
        sum += ls.second - ls.first + 1;
        ls = x;
      } else {
        ls.second = max(ls.second, x.second);
      }
    }
    sum += ls.second - ls.first + 1;
    if (sum + sum <= t) {
      ans = n - p;
      r = p - 1;
    } else {
      l = p + 1;
    }
  }
  cout << ans << endl;
}
