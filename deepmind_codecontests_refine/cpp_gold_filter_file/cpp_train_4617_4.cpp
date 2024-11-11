#include <bits/stdc++.h>
long long a[10001000];
int flag = 0;
long long i;
long long k;
long long n;
long long m;
long long cnt = 1;
long long x;
long long tri;
long long Amin;
long long Bmax;
long long mindiff;
long long maxdiff;
long long ans = 0;
long long mmax;
int main() {
  {
    scanf("%I64d", &n);
    mmax = 0;
    memset(a, 0, sizeof(a));
    ans = 0;
    scanf("%I64d", &m);
    for (k = 1; k <= n; k++) {
      scanf("%I64d", &a[k]);
    }
    for (cnt = 1; cnt * n <= m; cnt++) {
      flag = 0;
      ans = 0;
      tri = cnt * (cnt - 1) / 2 * n;
      Amin = tri + cnt;
      Bmax = cnt * m - tri;
      mindiff = cnt;
      maxdiff = m - cnt;
      Bmax = ((Bmax) < (a[n]) ? (Bmax) : (a[n]));
      for (k = 1; k < n; k++)
        Bmax = ((Bmax) < (a[k] - (k - 1) * mindiff + maxdiff)
                    ? (Bmax)
                    : (a[k] - (k - 1) * mindiff + maxdiff));
      x = Bmax;
      for (k = n; k >= 1; k--) {
        if (k != n) x -= mindiff;
        x = ((x) < (a[k]) ? (x) : (a[k]));
        if ((Bmax - x) > maxdiff || x < Amin) {
          flag = -1;
          break;
        }
        ans += x;
      }
      if (flag != -1) {
        mmax = ((mmax) > (ans) ? (mmax) : (ans));
      }
    }
    printf("%I64d\n", mmax);
  }
  return 0;
}
