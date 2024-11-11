#include <bits/stdc++.h>
using namespace std;
const long long inf = 0;
const double eps = 0;
const long long ms = 0;
const long long md = 0;
void solve() {
  long long n;
  scanf("%lld", &n);
  long long k = floor(log2(n));
  long long ans = n * (n + 1) / 2;
  ans -= 2 * (pow(2, k + 1) - 1);
  printf("%lld\n", ans);
}
int32_t main() {
  ios::sync_with_stdio(false);
  long long T;
  scanf("%lld", &T);
  while (T--) solve();
}
