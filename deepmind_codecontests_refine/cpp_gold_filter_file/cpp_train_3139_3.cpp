#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long h, n;
  cin >> h >> n;
  long long d[n];
  long long y = h;
  long long ans = -1;
  long long mn = 0;
  long long zz = 0;
  for (long long i = 0; i < n; i++) {
    cin >> d[i];
    zz += d[i];
    mn = min(mn, zz);
  }
  for (long long i = 0; i < n; i++) {
    y += d[i];
    if ((y) <= 0) {
      ans = i + 1;
      break;
    }
  }
  if (ans == (-1)) {
    if (y >= h) {
      cout << "-1";
    } else {
      long long x = h - y;
      long long z = (h + mn) / x;
      long long anss = n * z;
      h -= (z * x);
      if (h <= 0) {
        cout << anss;
        return 0;
      } else {
        for (long long i = 0; i < n; i++) {
          h += d[i];
          anss++;
          if (h <= 0) {
            break;
          }
        }
        if (h <= 0) {
          cout << anss;
          return 0;
        }
        for (long long i = 0; i < n; i++) {
          h += d[i];
          anss++;
          if (h <= 0) {
            break;
          }
        }
        cout << anss;
        return 0;
      }
    }
  } else
    cout << ans;
  return 0;
}
