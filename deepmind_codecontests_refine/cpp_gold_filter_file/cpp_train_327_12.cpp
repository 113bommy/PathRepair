#include <bits/stdc++.h>
using namespace std;
long long ww[4][4] = {
    {-1, 0, -1, 0}, {1, 0, 1, 0}, {0, -1, 0, -1}, {0, 1, 0, 1}};
signed main() {
  long long t;
  cin >> t;
  map<char, long long> xa, ya, za;
  xa['W'] = 0;
  xa['S'] = 0;
  xa['A'] = -1;
  xa['D'] = 1;
  ya['W'] = 1;
  ya['S'] = -1;
  ya['A'] = 0;
  ya['D'] = 0;
  za['W'] = 0;
  za['S'] = 1;
  za['A'] = 2;
  za['D'] = 3;
  while (t > 0) {
    t--;
    long long a = 0, b = 0, c = 0, d = 0;
    string s;
    cin >> s;
    long long x = 0, y = 0;
    long long n = s.size();
    long long dp[n + 4][4];
    long long qp[n + 4][4];
    long long val[n + 4][2];
    long long ans = 1e18;
    memset(dp, 0, sizeof(dp));
    memset(val, 0, sizeof(val));
    memset(qp, 0, sizeof(qp));
    for (long long i = 0; i < s.size(); i++) {
      x += xa[s[i]];
      y += ya[s[i]];
      val[i][0] = x;
      val[i][1] = y;
      a = min(x, a);
      b = min(y, b);
      c = max(x, c);
      d = max(y, d);
      qp[i][0] = a;
      qp[i][1] = b;
      qp[i][2] = c;
      qp[i][3] = d;
    }
    long long o = 1, oo = 0;
    ans = min(ans, (c - a + (long long)1) * (d - b + (long long)1));
    long long aa[4];
    aa[0] = 1e9;
    aa[1] = 1e9;
    aa[2] = -1e9;
    aa[3] = -1e9;
    for (long long i = n - 1; i >= 0; i--) {
      if (i >= 0) {
        long long x = val[i][0];
        long long y = val[i][1];
        aa[0] = min(x, aa[0]);
        aa[1] = min(y, aa[1]);
        aa[2] = max(x, aa[2]);
        aa[3] = max(y, aa[3]);
        for (long long j = 0; j < 4; j++) {
          long long xx[4];
          xx[0] = min(qp[i][0], aa[0] + ww[j][0]);
          xx[1] = min(qp[i][1], aa[1] + ww[j][1]);
          xx[2] = max(qp[i][2], aa[2] + ww[j][2]);
          xx[3] = max(qp[i][3], aa[3] + ww[j][3]);
          ans = min(ans, (xx[2] - xx[0] + o) * (xx[3] - xx[1] + o));
        }
      }
    }
    long long uu = (c - a + (long long)1) * (d - b + (long long)1);
    cout << ans << endl;
  }
}
