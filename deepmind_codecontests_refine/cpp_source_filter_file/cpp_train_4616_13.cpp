#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const int maxn = 100000;
const long long inf = (~0ull) >> 2;
long long p[maxn];
long long yue[2][maxn];
long long all[maxn];
int ynum[2], an, a[maxn];
long long base, ans[3], tmp[3], res, suf, v;
int main() {
  int T, i, j, k, ii, l, r;
  scanf("%d", &T);
  long long trv;
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d", &k);
    ynum[0] = ynum[1] = 0;
    v = 1;
    yue[0][ynum[0]++] = 1;
    yue[1][ynum[1]++] = 1;
    for (ii = 0; ii < k; ++ii) {
      scanf("%I64d%d", &p[ii], &a[ii]);
      for (i = 1; i <= a[ii]; ++i) v *= p[ii];
    }
    trv = min(ceil(pow(v, 1.0 / 3)) * 500, ceil(pow(v, 1.0 / 2)));
    for (ii = 0; ii < k; ++ii) {
      base = p[ii];
      for (i = 1; i <= a[ii]; ++i, base *= p[ii])
        for (j = 0; j < ynum[0]; ++j) {
          if (yue[0][j] * base > trv) continue;
          yue[0][ynum[1]] = yue[1][ynum[1]] = yue[0][j] * base;
          ++ynum[1];
        }
      ynum[0] = ynum[1];
    }
    for (i = an = 0; i < ynum[0]; ++i) all[an++] = yue[0][i];
    sort(all, all + an);
    an = unique(all, all + an) - all;
    suf = inf;
    trv = floor(pow(v, 1.0 / 3));
    int beg = lower_bound(all, all + an, trv) - all;
    for (i = max(beg - 2000, 0); i < beg + 2000 && i < an; ++i) {
      for (j = i; j < i + 11 && j < an; ++j) {
        tmp[0] = all[i];
        tmp[1] = all[j];
        if (v % (tmp[0] * tmp[1])) continue;
        tmp[2] = v / (tmp[0] * tmp[1]);
        res = 2 * (tmp[0] * tmp[1] + tmp[1] * tmp[2] + tmp[0] * tmp[2]);
        if (res < suf) {
          suf = res;
          for (k = 0; k < 3; ++k) ans[k] = tmp[k];
        }
      }
    }
    printf("%I64d %I64d %I64d %I64d\n", suf, ans[0], ans[1], ans[2]);
  }
  return 0;
}
