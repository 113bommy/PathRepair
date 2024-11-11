#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e17;
long long scale = 1e8;
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  long long ans = 1.0;
  for (long long i = 0; i < r; i++) {
    ans *= n;
    n--;
  }
  while (r > 0) ans /= r, r--;
  return ans;
}
long long get_prob(long long n, long long m) {
  long long u = nCr(n - m, 2) == 0 ? 0.0 : nCr(n - m, 2);
  long long v = nCr(n, 3);
  long long w = nCr(m, 2);
  long long x = nCr(n, 3);
  long long y = nCr(m, 3);
  long long z = nCr(n, 3);
  return scale * (m * u) / (v * 2) + scale * w * (n - m) / x + scale * y / z;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  double p;
  cin >> n >> p;
  long long pp = p * scale;
  long long i;
  for (i = 0; i <= n; i++) {
    if (pp <= get_prob(n, i)) break;
  }
  cout << i << endl;
}
