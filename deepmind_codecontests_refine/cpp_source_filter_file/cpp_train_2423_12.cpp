#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
using pil = pair<long long, long long>;
using pli = pair<long long, long long>;
using pll = pair<long long, long long>;
using pdd = pair<long double, long double>;
using vint = vector<long long>;
using vll = vector<long long>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;
const long long N = 2e5 + 5;
const long long Inf = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long Mod = 998244353;
const long double eps = 1e-9;
void io() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
long long a[101];
long long n;
void solve() {
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n / 2; ++i) {
    cout << a[i + 1] << ' ' << -a[i] << ' ';
  }
  cout << '\n';
}
signed main() {
  io();
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
