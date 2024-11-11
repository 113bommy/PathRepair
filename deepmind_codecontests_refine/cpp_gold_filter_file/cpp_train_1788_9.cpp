#include <bits/stdc++.h>
using namespace std;
int sum[1111][1111];
long long tmp0, tmptype;
long long getres(long long sum0, long long sum1, long long n, long long nown,
                 bool type) {
  if (n < nown) {
    tmp0 = n, tmptype = type;
    return 0;
  }
  long long ssum0 = sum0, ssum1 = sum1;
  long long nowres = sum1, nowx = nown;
  while (nowx * 2 <= n) {
    long long tmp0 = sum0, tmp1 = sum1;
    sum0 = tmp0 + tmp1, sum1 = tmp1 + tmp0;
    nowres += tmp0;
    nowx *= 2;
  }
  return nowres + getres(ssum1, ssum0, n - nowx, nown, !type);
}
long long doqpow(long long n, long long nown, long long nowm, bool type) {
  long long sum1 = sum[nown][nowm], sum0 = nown * nowm - sum1;
  if (type) swap(sum0, sum1);
  long long xx = getres(sum0, sum1, n, nown, 0);
  if (tmptype ^ type)
    return xx + tmp0 * nowm - sum[tmp0][nowm];
  else
    return xx + sum[tmp0][nowm];
}
long long solve(long long n, long long m, long long nown, long long nowm) {
  long long sumnow = doqpow(n, nown, nowm, 0);
  long long resnow = getres(n * nowm - sumnow, sumnow, m, nowm, 0);
  return resnow + doqpow(n, nown, tmp0, tmptype);
}
char s[1111];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i < n + 1; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) {
      sum[i][j + 1] = s[j] - '0';
      sum[i][j + 1] += sum[i][j] + sum[i - 1][j + 1] - sum[i - 1][j];
    }
  }
  int x1, x2, y1, y2;
  while (q--) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%I64d\n", solve(x2, y2, n, m) - solve(x2, y1 - 1, n, m) -
                          solve(x1 - 1, y2, n, m) +
                          solve(x1 - 1, y1 - 1, n, m));
  }
}
