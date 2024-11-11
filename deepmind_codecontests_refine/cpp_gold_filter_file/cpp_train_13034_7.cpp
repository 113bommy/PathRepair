#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long test, n, m, k, x, y, z, l, r, ans, a[N], b[N];
void solve() {
  cin >> n;
  long long s = 0, xr = 0;
  for (long long i = 1; i <= n; i++) cin >> x, s += x, xr ^= x;
  cout << 2 << "\n" << xr << " " << xr + s << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) solve();
}
