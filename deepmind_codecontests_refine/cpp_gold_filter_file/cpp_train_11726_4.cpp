#include <bits/stdc++.h>
using namespace std;
long long t;
const long long M = 1e9 + 7;
const long long inf = INT64_MAX;
long long max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long min(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
long long fspow(long long x, long long y) {
  long long ans;
  if (y == 0) return 1;
  ans = fspow(x, y / 2);
  if (y % 2 == 0) return ((ans * ans) % M);
  return (x * ((ans * ans) % M)) % M;
}
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  if (y == 0) return x;
  return gcd(x % y, y);
}
long long p2(long long x) {
  long long ans = 0;
  while (x > 1) {
    ans++;
    x /= 2;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  t = 1;
  while (t--) {
    long long h;
    cin >> h;
    long long a[h + 1];
    for (long long i = 0; i < h + 1; i++) cin >> a[i];
    bool ok = 0;
    long long v = 0;
    for (long long i = 1; i < h + 1; i++) {
      if (a[i] >= 2 && a[i - 1] >= 2) {
        ok = 1;
        v = i;
        break;
      }
    }
    if (ok) {
      cout << "ambiguous\n";
      long long cur = 0;
      for (long long i = 0; i < h + 1; i++) {
        for (long long j = 0; j < a[i]; j++) {
          cout << cur << " ";
        }
        cur += a[i];
      }
      cur = 0;
      cout << endl;
      for (long long i = 0; i < h + 1; i++) {
        if (i == v) a[i]--;
        for (long long j = 0; j < a[i]; j++) {
          cout << cur << " ";
        }
        if (i == v) cout << cur - 1 << " ";
        if (i == v) a[i]++;
        cur += a[i];
      }
    } else {
      cout << "perfect\n";
    }
  }
}
