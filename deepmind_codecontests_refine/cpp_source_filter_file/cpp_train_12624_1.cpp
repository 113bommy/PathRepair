#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int pct(int x) { return __builtin_popcount(x); }
int bit(int x) { return 31 - __builtin_clz(x); }
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int maxn = 1e5 * 3 + 20;
int n, _, q, k;
void solve() {
  cin >> _;
  while (_--) {
    cin >> n;
    string t;
    cin >> t;
    set<int> bag[2];
    vector<int> ans(n);
    int cnt = 0;
    for (signed i = 0; i < n; i++) {
      int x = t[i] - '0';
      if (bag[x ^ 1].empty()) {
        bag[x].insert(++cnt);
        ans[i] = cnt;
      } else {
        ans[i] = *bag[x ^ 1].begin();
        bag[x ^ 1].erase(ans[i]);
        bag[x].insert(ans[i]);
      }
    }
    cout << cnt - 2 << endl;
    for (signed i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
