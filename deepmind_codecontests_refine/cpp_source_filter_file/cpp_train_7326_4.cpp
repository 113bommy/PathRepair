#include <bits/stdc++.h>
using namespace std;
const int ppr = 257;
const long long INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int N = 1e6 + 123;
const long double pi = 3.141592653589793238462643;
long long n, a[N], xr, rx, b[3][N], mx, cz;
inline void add(long long x) {
  long long v = 0;
  for (long long i = 50; i >= 0; i--) {
    long long bit = (x & (1ll << i));
    if (bit) bit = 1;
    if (!b[bit][v]) b[bit][v] = ++cz;
    v = b[bit][v];
  }
}
inline long long get(long long x) {
  long long v = 0, ans = 0;
  for (long long i = 50; i >= 0; i--) {
    long long bit = (x & (1ll << i));
    if (bit) bit = 1;
    if (b[bit ^ 1][v]) {
      ans += (1ll << i);
      v = b[bit ^ 1][v];
    } else {
      v = b[bit][v];
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    xr ^= a[i];
  }
  mx = xr;
  for (long long i = n; i > 0; i--) {
    xr ^= a[i];
    rx ^= a[i];
    add(rx);
    mx = max(mx, max(get(xr), max(xr, rx)));
  }
  cout << mx;
  return 0;
}
