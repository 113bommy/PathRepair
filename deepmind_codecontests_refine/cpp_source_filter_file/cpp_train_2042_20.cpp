#include <bits/stdc++.h>
using namespace std;
const double eps = 0.000000000000001;
string convertstring(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
bool pr[1000007];
long long a[1000007], lo[1000007], hi[1000007], cum[1000007];
int main() {
  long long n, X, Y, i, j;
  scanf("%lld%lld%lld", &n, &X, &Y);
  ;
  long long mx = X / Y;
  for (i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    ;
  }
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; ++i) cum[i] = cum[i - 1] + a[i];
  long long ans = 0, pp = 99999999999999999ll;
  for (i = 0; i < 1000007; ++i) {
    lo[i] = lower_bound(a + 1, a + n + 1, i) - a;
    hi[i] = upper_bound(a + 1, a + n + 1, i) - a - 1;
  }
  for (i = 2; i < 1000007; ++i) {
    ans = 0;
    for (j = i; j < 1000007; j += i) {
      pr[i] = 1;
      int x = hi[j], y = lo[max(j - i + 1, j - mx)], z = lo[j - i + 1];
      assert(x <= n);
      if (x < y) {
        if (z <= x) {
          ans += (x - z + 1) * X;
        }
        continue;
      }
      ans += (-(cum[x] - cum[y - 1]) + (x - y + 1) * j) * Y + (y - z) * X;
      if (ans > n * Y) break;
    }
    pp = min(pp, ans);
  }
  cout << pp << endl;
  return 0;
}
