#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
signed main() {
  long long q;
  cin >> q;
  for (long long j = 0; j < q; j++) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long x, a1, y, b1, k;
    cin >> x >> a1 >> y >> b1 >> k;
    if (n == 1) {
      long long ans = 0;
      if (a1 == 1) ans += a[0] / 100 * x;
      if (b1 == 1) ans += a[0] / 100 * y;
      if (ans >= k) {
        cout << 1 << endl;
        continue;
      } else {
        cout << -1 << endl;
        continue;
      }
    }
    long long l = -1, r = n, ca = 0;
    while (l + 1 < r) {
      long long m = (l + r) / 2;
      long long ans = 0;
      long long cur = n - 1;
      long long step = a1 * b1 / gcd(a1, b1);
      vector<long long> u1(n, 0);
      vector<long long> u2(n, 0);
      for (long long pos = step - 1; pos <= m; pos += step) {
        ans += (a[cur] / 100) * (x + y);
        cur--;
        u1[pos] = 1;
        u2[pos] = 1;
      }
      long long ad1 = 0, cur1 = cur;
      for (long long pos = a1 - 1; pos <= m; pos += a1) {
        if (u1[pos] == 1) continue;
        ad1 += (a[cur1] / 100) * x;
        cur1--;
        u1[pos] = 1;
      }
      for (long long pos = b1 - 1; pos <= m; pos += b1) {
        if (u1[pos] == 1) continue;
        ad1 += (a[cur1] / 100) * y;
        cur1--;
        u1[pos] = 1;
      }
      long long ad2 = 0, cur2 = cur;
      for (long long pos = b1 - 1; pos <= m; pos += b1) {
        if (u2[pos] == 1) continue;
        ad2 += (a[cur2] / 100) * y;
        cur2--;
        u2[pos] = 1;
      }
      for (long long pos = a1 - 1; pos <= m; pos += a1) {
        if (u2[pos] == 1) continue;
        ad2 += (a[cur2] / 100) * x;
        cur2--;
        u2[pos] = 1;
      }
      ans += max(ad1, ad2);
      if (ans >= k) {
        r = m;
        ca = ans;
      } else {
        l = m;
      }
    }
    if (ca < k) {
      cout << -1 << endl;
    } else {
      cout << r + 1 << endl;
    }
  }
}
