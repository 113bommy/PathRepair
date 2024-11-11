#include <bits/stdc++.h>
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int r, s, p;
double dp[108][108][108], zz, s1, s2, s3;
int main() {
  cin.tie(0);
  cout.tie(0);
  cin >> r >> s >> p;
  dp[r][s][p] = 1.0;
  for (int i(r); i >= (0); --i) {
    for (int j(s); j >= (0); --j) {
      for (int k(p); k >= (0); --k) {
        zz = (i + j + k) * (i + j + k - 1) / 2 - (i * (i - 1) / 2) -
             j * (j - 1) / 2 - k * (k - 1) / 2;
        if (k && j) dp[i][j][k - 1] += dp[i][j][k] * (double)j * (double)k / zz;
        if (j && i) dp[i][j - 1][k] += dp[i][j][k] * (double)j * (double)i / zz;
        if (i && k) dp[i - 1][j][k] += dp[i][j][k] * (double)i * (double)k / zz;
        if (!i && !j && k) s3 += dp[i][j][k];
        if (!i && !k && j) s2 += dp[i][j][k];
        if (!k && !j && i) s1 += dp[i][j][k];
      }
    }
  }
  printf("%.10lf %.10lf %.10lf\n", s1, s2, s3);
  return 0;
}
