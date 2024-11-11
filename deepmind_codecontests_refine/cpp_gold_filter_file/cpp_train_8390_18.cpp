#include <bits/stdc++.h>
using namespace std;
int64_t mod = 1e17;
int64_t mod1 = 1e9 + 5;
int64_t power(int64_t a, int64_t b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return power(((((a) % mod) * ((a) % mod)) % mod), b / 2) % mod;
  else
    return (((a) % mod) *
            (power(((((a) % mod) * ((a) % mod)) % mod), b / 2) % mod)) %
           mod;
}
inline int64_t inverse(int64_t a, int64_t md) {
  a %= md;
  if (a < 0) a += md;
  int64_t b = md, u = 0, v = 1;
  while (a) {
    int64_t t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
const int64_t ce = 1e9 + 7;
int64_t fast_mod(int64_t input) { return input < ce ? input : input % ce; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t n, k;
  cin >> n >> k;
  int64_t a[n + 1];
  int64_t ch = 0;
  int64_t sz = 0;
  for (int64_t i = 0; i < n; i++) {
    int64_t p;
    cin >> p;
    if (p == 0 and ch == 0) continue;
    ch = 1;
    a[sz] = p;
    sz++;
  }
  n = sz;
  if (n == 2) {
    if (*max_element(a, a + n) >= k) {
      cout << 0 << '\n';
      return 0;
    }
    int64_t t = (k - a[1] + a[0] - 1) / a[0];
    cout << t << '\n';
    return 0;
  }
  if (n == 3) {
    if (*max_element(a, a + n) >= k) {
      cout << 0 << '\n';
      return 0;
    }
    int64_t lo = 1, hi = 2 * 1e9, ans = hi;
    while (lo < hi) {
      int64_t mid = (lo + hi) / 2;
      int64_t th = (mid * (mid + 1)) / 2;
      int64_t ch = k + 100;
      if (a[0] >= ((ch + th - 1) / th)) {
        hi = mid;
        if (ans == hi) break;
        ans = hi;
        continue;
      }
      int64_t sum = th * a[0];
      sum += mid * a[1];
      sum += a[2];
      if (sum >= k) {
        hi = mid;
        if (ans == hi) break;
        ans = hi;
      } else {
        lo = mid + 1;
      }
    }
    if (ans != 1) {
      int64_t mid = ans - 1;
      int64_t th = (mid * (mid + 1)) / 2;
      int64_t ch = k + 100;
      if (a[0] >= ((ch + th - 1) / th)) {
        ans--;
      } else {
        int64_t sum = th * a[0];
        sum += mid * a[1];
        sum += a[2];
        if (sum >= k) ans--;
      }
    }
    cout << ans;
    return 0;
  }
  int64_t ans = 0;
  while (1) {
    if (*max_element(a, a + n) >= k) {
      cout << ans;
      return 0;
    }
    for (int64_t i = 1; i < n; i++) a[i] += a[i - 1];
    ans++;
  }
}
