#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
long long tot;
int s1[35][maxn], s2[35][maxn], v[maxn], pre[maxn];
map<int, int> last;
inline int rd() {
  int ret = 0, f = 1;
  char gc = getchar();
  while (gc < '0' || gc > '9') {
    if (gc == '-') f = -f;
    gc = getchar();
  }
  while (gc >= '0' && gc <= '9') ret = ret * 10 + gc - '0', gc = getchar();
  return ret * f;
}
int main() {
  n = rd();
  int i, j, rs, ls;
  for (i = 1; i <= n; i++) {
    v[i] = rd(), pre[i] = last[v[i]], last[v[i]] = i;
    for (j = 0; j <= 30; j++) {
      if (v[i] & (1 << j))
        s1[j][i] = i;
      else
        s1[j][i] = s1[j][i - 1];
    }
  }
  for (j = 0; j <= 30; j++) s2[j][n + 1] = n + 1;
  for (i = n; i >= 1; i--)
    for (j = 0; j <= 30; j++) {
      if (v[i] & (1 << j))
        s2[j][i] = i;
      else
        s2[j][i] = s2[j][i + 1];
    }
  for (i = 1; i <= n; i++) {
    ls = 1, rs = n;
    for (j = 0; j <= 30; j++) {
      if (!((v[i] >> j) & 1))
        ls = max(ls, s1[j][i - 1] + 1), rs = min(rs, s2[j][i + 1] - 1);
    }
    ls = max(ls, pre[i] + 1);
    tot += (long long)(rs - i + 1) * (i - ls + 1) - 1;
  }
  tot = (long long)n * (n - 1) / 2 - tot;
  printf("%I64d", tot);
  return 0;
}
