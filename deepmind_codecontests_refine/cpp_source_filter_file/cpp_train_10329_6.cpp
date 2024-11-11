#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
const long long int mxn = 2e5 + 10;
long long int mul(long long int x, long long int y, long long int mod) {
  long long int res = x * y;
  if (res >= mod) res %= mod;
  return res;
}
long long int add(long long int x, long long int y, long long int mod) {
  long long int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}
long long int sub(long long int x, long long int y, long long int mod) {
  long long int res = x - y;
  if (res < 0) res += mod;
  return res;
}
long long int power(long long int x, long long int y, long long int mod) {
  long long int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x, mod);
    y = y >> 1;
    x = mul(x, x, mod);
  }
  return res;
}
long long int fact[mxn];
void init(long long int mod) {
  fact[0] = 1;
  for (long long int i = 1; i < mxn; i++) {
    fact[i] = mul(i, fact[i - 1], mod);
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  init(m);
  long long int ans = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    long long int x = mul(fact[n - i], n - i, m);
    x = mul(x, fact[i + 1], m);
    ans = add(ans, x, m);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t = 1;
  for (long long int tt = 1; tt <= t; tt++) {
    solve();
  }
}
