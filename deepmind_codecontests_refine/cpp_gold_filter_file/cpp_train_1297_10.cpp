#include <bits/stdc++.h>
using namespace std;
const int MAXN = 52, MAXL = 21, MAXM = 1 << 20;
int n, len, lim, tot, msk, chosen[MAXM];
long long d[MAXM];
double ans = 0.0, pro[MAXM];
char s[MAXN][MAXL];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", s[i]);
  len = strlen(s[0]);
  lim = 1 << len;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      msk = 0;
      for (int k = 0; k < len; ++k)
        if (s[i][k] == s[j][k]) msk |= 1 << k;
      d[msk] |= 1LL << i | 1LL << j;
    }
  for (int i = lim - 1; i >= 0; --i)
    for (int j = 0; j < len; ++j)
      if (i & (1 << j)) d[i ^ (1 << j)] |= d[i];
  pro[0] = 1.0;
  for (int i = 0; i < lim; ++i) {
    tot = 0;
    chosen[i] = chosen[i >> 1] + (i & 1);
    for (int j = 0; j < len; ++j)
      if (!(i & (1 << j))) pro[i ^ (1 << j)] += pro[i] / (len - chosen[i]);
    for (long long j = d[i]; j; j -= (j & -j)) ++tot;
    ans += pro[i] * tot;
  }
  printf("%.11lf\n", ans / (double)n);
  return 0;
}
