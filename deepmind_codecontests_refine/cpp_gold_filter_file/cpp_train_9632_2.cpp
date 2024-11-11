#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const int CS = 22;
int cmax[N][CS], cmin[N][CS], ans[N];
int lt[CS];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &cmax[i][0]);
    cmax[i][0] *= 100;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &cmin[i][0]);
  int cs = 1;
  for (int g = 1; g < n; g <<= 1, cs++) {
    int gg = g << 1;
    for (int i = 1; i <= n; i++) {
      if (i + gg - 1 > n)
        cmax[i][cs] = cmin[i][cs] = 0;
      else {
        cmax[i][cs] = max(cmax[i][cs - 1], cmax[i + g][cs - 1]);
        cmin[i][cs] = min(cmin[i][cs - 1], cmin[i + g][cs - 1]);
      }
    }
  }
  lt[0] = 1;
  for (int i = 1; i < cs; i++) lt[i] = lt[i - 1] << 1;
  for (int i = 1; i <= n; i++) {
    ans[i] = 0;
    int tmax = 0, tmin = 10000000;
    int mid = i;
    for (int j = cs - 1; j >= 0; j--) {
      if (cmax[mid][j] > 0) {
        int tmax2 = max(tmax, cmax[mid][j]);
        int tmin2 = min(tmin, cmin[mid][j]);
        ans[i] = max(ans[i], min(tmax2, tmin2));
        if (tmax2 <= tmin2) {
          tmax = tmax2;
          tmin = tmin2;
          if (tmax == tmin) break;
          mid += lt[j];
          if (mid > n) break;
        }
      }
    }
  }
  sort(ans + 1, ans + n + 1);
  double p = 1.0;
  double res = 0;
  for (int i = 1; i <= n - k + 1; i++) {
    if (p < 1e-20) break;
    double pp = k * 1.0 / (n - i + 1);
    res += p * pp * ans[i];
    p *= (1 - pp);
  }
  printf("%.12f", res);
  return 0;
}
