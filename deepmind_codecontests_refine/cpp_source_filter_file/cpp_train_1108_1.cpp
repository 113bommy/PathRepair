#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007;
long long t[(1 << 20)], z[(1 << 20)];
long long n, r, k;
bool ok(long long d) {
  for (int i = 0; i < n; ++i) z[i] = 0;
  long long asd = 0, c = 0;
  for (int i = 0; i < r; ++i) asd += t[i];
  for (int i = 0; i < n; ++i) {
    if (i - r > 0) asd -= t[i - r - 1] + z[i - r - 1];
    if (i + r < n) asd += t[i + r];
    long long h = max(0LL, d - asd);
    asd += h;
    c += h;
    if (c > k) return 0;
    z[i] += h;
  }
  return c <= k;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r >> k;
  for (int i = 0; i < n; ++i) cin >> t[i];
  long long V = -1;
  for (long long b = 1e18; b >= 1; b /= 2) {
    while (ok(V + b)) V += b;
  }
  cout << V;
}
