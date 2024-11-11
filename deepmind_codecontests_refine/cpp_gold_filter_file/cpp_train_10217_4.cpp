#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 9e18 + 2e17;
const int inf = 2e9;
const int N = 1e6 + 22;
const double eps = 1e-10;
const double PI = 3.14159265;
int n, m;
int fac[N], ifac[N], mpow[N], npow[N];
int _mul(int a, int b) { return (1LL * a * b) % mod; }
int _add(int a, int b) { return (a + b) % mod; }
int modp(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = _mul(res, a);
    a = _mul(a, a);
    b >>= 1;
  }
  return res;
}
void _prec() {
  fac[0] = 1;
  for (int i = (int)1; i < (int)N; i++) fac[i] = _mul(fac[i - 1], i);
  ifac[N - 1] = modp(fac[N - 1], mod - 2);
  for (int i = (int)N - 1; i >= (int)1; i--) ifac[i - 1] = _mul(ifac[i], i);
  mpow[0] = npow[0] = 1;
  for (int i = (int)1; i < (int)N; i++)
    mpow[i] = _mul(mpow[i - 1], m), npow[i] = _mul(npow[i - 1], n);
}
void _solve() {
  int u, v;
  cin >> n >> m >> u >> v;
  _prec();
  int ways = 1;
  int ans = 0, temp, cayley = 1;
  for (int i = (int)1; i <= (int)m; i++) {
    if (i + 2 <= n)
      cayley = _mul(i + 1, npow[n - i - 2]);
    else
      cayley = 1;
    temp = _mul(ways, cayley);
    temp = _mul(temp, ifac[i - 1]);
    temp = _mul(temp, ifac[m - i]);
    temp = _mul(temp, mpow[n - i - 1]);
    ans = _add(ans, temp);
    ways = _mul(ways, n - i - 1);
  }
  ans = _mul(ans, fac[m - 1]);
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  _solve();
  return 0;
}
