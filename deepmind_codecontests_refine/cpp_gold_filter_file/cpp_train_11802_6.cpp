#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long m, l, r, k;
long long fib(long long n) {
  long long v1 = 1, v2 = 1, v3 = 0;
  long long cnt1 = 0;
  for (long long i = 62; i >= 0; i--) {
    if (cnt1 >= 1) {
      long long c = (v2 * v2) % m;
      long long nv1 = (v1 * v1 + c) % m, nv2 = ((v1 + v3) * v2) % m,
                nv3 = (v3 * v3 + c) % m;
      if (n & (1LL << i)) {
        v1 = (nv1 + nv2) % m;
        v2 = nv1;
        v3 = nv2;
      } else
        v1 = nv1, v2 = nv2, v3 = nv3;
    }
    if (n & (1LL << i)) cnt1++;
  }
  return v2;
}
inline long long ceil(long long x, long long d) { return (x - 1) / d + 1; }
bool sat(long long v) { return r / v - ceil(l, v) + 1 >= k; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> l >> r >> k;
  long long mx = 1;
  for (long long x = 1; x * x <= r; x++) {
    if (sat(x)) mx = max(mx, x);
    if (sat(r / x)) mx = max(mx, r / x);
  }
  for (long long x = 1; x * x <= l; x++) {
    if (l % x == 0 && sat(l / x))
      mx = max(mx, l / x);
    else if (x > 1 && sat(l / (x - 1)))
      mx = max(mx, l / (x - 1));
  }
  cout << fib(mx) % m << endl;
  return 0;
}
