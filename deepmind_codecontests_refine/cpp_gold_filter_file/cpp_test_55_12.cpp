#include <bits/stdc++.h>
using namespace std;
template <class t1, class t2>
bool ckmin(t1& a, t2 b) {
  return a < b ? 1 : a = b, 0;
}
template <class t1, class t2>
bool ckmax(t1& a, t2 b) {
  return a > b ? 1 : a = b, 0;
}
const long long mod = 1e9 + 7;
const long long mod2 = 1e9 + 6;
const int maxn = 3e5 + 8;
char str[maxn];
long long qp(long long a, long long b, long long m) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
  }
  return res;
}
void solve(void) {
  int n;
  cin >> n;
  long long c = qp(2, n, mod2) + mod2;
  cout << 1LL * 6 * qp(4, c - 2, mod) % mod;
}
int main(void) {
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
