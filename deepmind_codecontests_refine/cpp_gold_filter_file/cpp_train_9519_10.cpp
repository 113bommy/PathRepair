#include <bits/stdc++.h>
using namespace std;
long long temp = 0, r, l, z, w, k = 0, m1, e, p, q, ans = 0, k1 = 0, k2 = 0,
          d = 0, a = 0, b = 0, s = 0, x, y, min1 = 1000000010, max1 = 0, m,
          c = 0, t = 0, i, n, c1 = 0, tot = 0, t1, k4 = 0, c2 = 0, j = 0,
          k3 = 0;
char ch, ch1, ch2;
string s2, s3;
signed main() {
  cin >> c >> d >> n >> m >> k;
  vector<long long> v;
  if (k >= n * m) {
    cout << 0;
    return 0;
  }
  k = n * m - k;
  for (i = 0; i <= 10000; i++) {
    for (j = 0; j <= 10000; j++) {
      if (i * n + j >= k) min1 = min(i * c + j * d, min1);
    }
  }
  cout << min1;
}
