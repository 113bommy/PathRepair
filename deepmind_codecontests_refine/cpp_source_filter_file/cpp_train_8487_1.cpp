#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
const int maxk = 60;
const double inf = 1e12;
int n, k;
int t[maxn];
int brgr;
long long int prefsum[maxn];
double prefraz[maxn];
double prefrec[maxn];
double dp[maxk][maxn];
double inter(int a, int b) {
  if (a == 0) return prefraz[b];
  return prefraz[b] - prefraz[a - 1] -
         (double)prefsum[a - 1] * (prefrec[b] - prefrec[a - 1]);
}
void rek(int l, int r, int lp, int rp) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int optp = lp;
  double optv = inter(optp, mid);
  if (lp > 0) optv += dp[brgr - 1][optp - 1];
  for (int i = lp + 1; i < min(mid + 1, rp + 1); i++) {
    if (dp[brgr - 1][i - 1] + inter(i, mid) < optv) {
      optv = dp[brgr - 1][i - 1] + inter(i, mid);
      optp = i;
    }
  }
  dp[brgr][mid] = optv;
  rek(l, mid - 1, lp, optp);
  rek(mid + 1, r, optp, rp);
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) dp[0][i] = inf;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    prefsum[i] = i == 0 ? t[i] : (prefsum[i - 1] + t[i]);
    prefraz[i] = i == 0 ? ((double)prefsum[i] / t[i])
                        : (prefraz[i - 1] + (double)prefsum[i] / t[i]);
    prefrec[i] = i == 0 ? ((double)1 / t[i])
                        : ((double)prefrec[i - 1] + (double)1 / t[i]);
  }
  for (int tt = 1; tt < k + 1; tt++) {
    brgr = tt;
    rek(0, n - 1, 0, n - 1);
  }
  printf("%lf\n", dp[k][n - 1]);
  return 0;
}
