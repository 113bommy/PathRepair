#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long mpow(long long a, long long b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long mpow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2, p);
  t1 *= t1;
  t1 %= p;
  if (b % 2) t1 *= a;
  t1 %= p;
  return t1;
}
long long modinverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
long long range(long long l, long long r) { return l + mt() % (r - l + 1); }
long long rev(long long v) { return mpow(v, MOD - 2); }
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long alpha = 0, sign = 1;
  set<long long> s;
  long long st = -1, en = -1;
  long long ans = 1;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] % 2) {
    st = 1;
    en = a[0] - 1;
    ans++;
  } else {
    st = a[0] / 2;
    en = a[0] / 2;
  }
  for (long long i = 1; i < n; i++) {
    long long alpha1 = a[i] - alpha;
    long long sign1 = -sign;
    if (a[i] % 2) {
      ans++;
      long long val = a[i] - alpha;
      if (sign > 0) {
        auto it = s.lower_bound(val);
        while (it != s.end()) {
          s.erase(it);
          it = s.lower_bound(val);
        }
      } else {
        auto it = s.lower_bound(-val + 1);
        while (it != s.begin()) {
          it--;
          s.erase(it);
          it = s.lower_bound(-val + 1);
        }
      }
      if (st >= a[i] && ((long long)(s).size()) == 0) {
        ans++;
        st = 1, en = a[i] - 1;
      } else if (st >= a[i]) {
        long long val = alpha1 + sign1 * (*(s.begin()));
        s.erase(s.begin());
        st = val, en = val;
      } else {
        long long t1 = a[i] - st, t2 = a[i] - en;
        st = max((long long)1, t2), en = max((long long)1, t1);
      }
    } else {
      long long mid = sign * (a[i] / 2 - alpha);
      if (s.find(mid) != s.end() || (st <= a[i] / 2 && en >= a[i] / 2)) {
        s.clear();
        st = a[i] / 2;
        en = a[i] / 2;
      } else {
        ans++;
        long long val = a[i] - alpha;
        if (sign > 0) {
          auto it = s.lower_bound(val);
          while (it != s.end()) {
            s.erase(it);
            it = s.lower_bound(val);
          }
        } else {
          auto it = s.lower_bound(-val + 1);
          while (it != s.begin()) {
            it--;
            s.erase(it);
            it = s.lower_bound(-val + 1);
          }
        }
        if (st >= a[i] && ((long long)(s).size()) == 0) {
          st = a[i] / 2, en = a[i] / 2;
        } else if (st >= a[i]) {
          long long val = alpha1 + sign1 * (*(s.begin()));
          s.erase(s.begin());
          st = val, en = val;
          s.insert(sign1 * (a[i] / 2 - alpha1));
        } else {
          long long t1 = a[i] - st, t2 = a[i] - en;
          st = max((long long)1, t2), en = max((long long)1, t1);
          s.insert(mid);
        }
      }
    }
    alpha = a[i] - alpha;
    sign *= -1;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
