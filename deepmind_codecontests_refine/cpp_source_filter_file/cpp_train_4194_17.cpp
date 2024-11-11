#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6, INF = 1e9 * 1e9 + 10;
long long find_k_stress(long long a, long long b, long long c, long long d,
                        long long t) {
  long long k = 0;
  long long fl = 0, c2 = 0;
  for (int j = 0; j < t - 1; j++) {
    long long tm = c;
    tm = min(tm, t * d - (j + 1) * d);
    if (tm == c) fl++;
    k -= tm * b;
    if (tm != c) {
      c2 -= tm * b;
    }
  }
  return k;
}
long long find_full(long long a, long long b, long long c, long long d,
                    long long t) {
  long long l = 0, r = MX;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (mid * d + c <= d * t) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
long long find_k(long long a, long long b, long long c, long long d,
                 long long t) {
  long long k = 0;
  long long full = find_full(a, b, c, d, t);
  k = -full * b * c;
  long long c2 = d * (t - full - 1);
  long long t2 = ((c2 + 0) * (t - full) * b) / 2;
  k -= ((c2 + 0) * (t - full) * b) / 2;
  return k;
}
long long dmg(long long a, long long b, long long c, long long d, long long t) {
  long long k = find_k(a, b, c, d, t);
  return a * t + k;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c * b) {
      cout << "-1\n";
    } else {
      long long l = 1, r = 100;
      while (r - l > 5) {
        long long mid = (l + r) / 2;
        if (dmg(a, b, c, d, mid) < dmg(a, b, c, d, mid + 1)) {
          l = mid;
        } else {
          r = mid + 1;
        }
      }
      long long ans = 0;
      for (int j = l; j <= r; j++) ans = max(ans, dmg(a, b, c, d, j));
      cout << ans << "\n";
    }
  }
  return 0;
}
