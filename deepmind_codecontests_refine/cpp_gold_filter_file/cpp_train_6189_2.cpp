#include <bits/stdc++.h>
using namespace std;
const int NBITS = 10;
const int M = (1 << NBITS);
const int TAM = 231;
double dp[2][M][2][TAM];
int dp0[M];
int cur, prv;
inline double f(const int m, const int dgt, const int cnt) {
  if (cnt < TAM) return dp[prv][m][dgt][cnt];
  return double(0);
}
int main() {
  for (int m = 0; m < M; ++m) {
    int& r = dp0[m];
    r = 0;
    while (((m >> r) & 1) == 0 && r < NBITS) r++;
  }
  double prob;
  int init, nSteps;
  cin >> init >> nSteps >> prob;
  prob /= double(100);
  double notProb = double(1) - prob;
  int nMask;
  for (int k = 0, mask, dgt, cnt; k <= nSteps; ++k) {
    cur = k & 1;
    prv = cur ^ 1;
    for (mask = 0; mask < M; ++mask)
      for (dgt = 0; dgt < 2; ++dgt)
        for (cnt = 0; cnt < TAM; ++cnt) {
          double& r = dp[cur][mask][dgt][cnt];
          r = 0;
          if (k == 0) {
            if (mask)
              r = double(dp0[mask]);
            else
              r = double(NBITS + (dgt == 0 ? cnt : 0));
          } else {
            if ((mask >> (NBITS - 1)) & 1)
              r = prob * f((mask << 1) & (M - 1), 1, (dgt == 1 ? cnt : 0) + 1);
            else
              r = prob * f((mask << 1) & (M - 1), 0, (dgt == 0 ? cnt : 0) + 1);
            nMask = ((mask + 1) & (M - 1));
            if (nMask == 0) {
              if (dgt == 0)
                r += notProb * f(nMask, 1, 1);
              else
                r += notProb * f(nMask, 0, cnt);
            } else
              r += notProb * f(nMask, dgt, cnt);
          }
        }
  }
  int dgt = (init >> NBITS) & 1;
  int cnt = 0;
  while (((init >> (NBITS + cnt)) & 1) == dgt) cnt++;
  printf("%.10lf\n", double(dp[nSteps & 1][init & (M - 1)][dgt][cnt]));
  return 0;
}
