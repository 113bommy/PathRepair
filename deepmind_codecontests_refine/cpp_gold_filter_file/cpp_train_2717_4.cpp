#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 5e5 + 5;
inline long long pw(long long a, long long n) {
  long long ans = 1, b = a;
  while (n) {
    if (n & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return ans;
}
inline long long Add(long long x, long long y) { return (x + y) % mod; }
inline long long Sub(long long x, long long y) {
  return ((x - y) % mod + mod) % mod;
}
inline long long Mul(long long x, long long y) { return x * y % mod; }
inline long long Div(long long x, long long y) {
  return x * pw(y, mod - 2) % mod;
}
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  int c1 = 0, c2 = 0, mx = -1e9, mn = 1e9;
  long long sum = 0;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i]);
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
    if (a[i] >= 0)
      sum += a[i], c1++;
    else
      sum -= a[i], c2++;
  }
  if (n == 1)
    cout << a[1];
  else {
    if (c1 == 0) sum += mx * 2;
    if (c2 == 0) sum -= mn * 2;
    cout << sum;
  }
}
