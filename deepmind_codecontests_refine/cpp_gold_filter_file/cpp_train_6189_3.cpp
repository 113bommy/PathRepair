#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x, k;
  double p;
  cin >> x >> k >> p;
  p /= 100.0;
  vector<vector<double> > dp(256, vector<double>(256, 0.0));
  vector<double> longdp(256, 0.0);
  if (x % 256 == 0) {
    int lev = 0;
    for (int pow2 = 1; (x & pow2) == 0; pow2 *= 2, lev++)
      ;
    longdp[lev] = 1.0;
  } else {
    int end = 8;
    while (x & (1 << end)) end++;
    dp[x % 256][end] = 1.0;
  }
  for (int step = 0; step < k; step++) {
    vector<vector<double> > nextdp(256, vector<double>(256, 0.0));
    vector<double> nextlongdp(256, 0.0);
    for (int m = 1; m < 256; m++)
      for (int end = 8; end + 1 < 256; end++) {
        {
          int nm = m * 2;
          int nend = 8;
          if (nm >= 256) {
            nm -= 256;
            nend = end + 1;
          }
          if (nm == 0)
            nextlongdp[8] += dp[m][end] * p;
          else
            nextdp[nm][nend] += dp[m][end] * p;
        }
        {
          int nm = m + 1;
          if (nm == 256)
            nextlongdp[end] += dp[m][end] * (1 - p);
          else
            nextdp[nm][end] += dp[m][end] * (1 - p);
        }
      }
    for (int lev = 8; lev + 1 < 256; lev++) {
      { nextlongdp[lev + 1] += longdp[lev] * p; }
      {
        if (lev == 8)
          nextdp[1][9] += longdp[lev] * (1 - p);
        else
          nextdp[1][8] += longdp[lev] * (1 - p);
      }
    }
    swap(dp, nextdp);
    swap(longdp, nextlongdp);
  }
  double result = 0.0;
  for (int m = 1; m < 256; m++)
    for (int end = 8; end < 256; end++) {
      int lev = 0;
      while ((m & (1 << lev)) == 0) lev++;
      result += dp[m][end] * lev;
    }
  for (int lev = 8; lev < 256; lev++) result += lev * longdp[lev];
  cout << fixed << setprecision(7) << result << '\n';
  return 0;
}
