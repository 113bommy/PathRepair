#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long const inf = 1e18, linf = 2e9, mod = 1e9 + 7;
int const mxn = 3e6 + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long par[mxn];
int main() {
  int n, k, mn = linf, mx = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mn = min(mn, a);
    mx = max(mx, a);
    par[a]++;
  }
  if (mn <= k + 1) {
    cout << mn;
    return 0;
  }
  for (int i = 1; i <= 1e6; i++) par[i] += par[i - 1];
  int ans = k + 1;
  for (int i = k + 1; i <= mn; i++) {
    int now = 0;
    for (int j = 1; i * j <= mx; j++) {
      now += par[i * j + k + 1] - par[i * j];
    }
    if (now == n) ans = i;
  }
  cout << ans;
}
