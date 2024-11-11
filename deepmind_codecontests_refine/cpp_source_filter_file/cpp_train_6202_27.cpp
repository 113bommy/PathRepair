#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long z = 1000000007;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % z;
      b--;
    } else {
      a = (a * a) % z;
      b = b >> 1;
    }
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long s, x1, x2;
    cin >> s >> x1 >> x2;
    long long t1, t2;
    cin >> t1 >> t2;
    long long p, d, d1;
    cin >> p >> d;
    long long q = abs(x2 - x1) * t2;
    long long ans = INT_MAX;
    if (x2 > x1) {
      if (p <= x1) {
        if (d == 1) {
          ans = (x2 - p) * t1;
        } else {
          ans = (x2 + p) * t1;
        }
      } else if (p > x1 && p <= x2) {
        if (d == -1) {
          ans = (x2 + p) * t1;
        } else {
          ans = (2 * s - p + x2) * t1;
        }
      } else if (p > x2) {
        if (d == 1) {
          ans = (2 * s - p + x2) * t1;
        } else {
          ans = (p + x2) * t1;
        }
      }
    } else {
      if (p <= x2) {
        if (d == 1) {
          ans = (2 * s - p - x2) * t1;
        } else {
          ans = (2 * s + p - x2) * t1;
        }
      } else if (p > x2 && p <= x1) {
        if (d == 1) {
          ans = (2 * s - p - x2) * t1;
        } else {
          ans = (2 * s + p - x2) * t1;
        }
      } else if (p > x1) {
        if (d == 1) {
          ans = (2 * s - p - x2) * t1;
        } else {
          ans = (p - x2) * t1;
        }
      }
    }
    cout << min(q, ans) << "\n";
  }
}
