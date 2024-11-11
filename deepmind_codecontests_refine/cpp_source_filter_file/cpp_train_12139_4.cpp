#include <bits/stdc++.h>
using namespace std;
int a[100010], bl[100010], fl[100010], fr[100010];
int f[(100010 / 433 + 3)][100010], res[(100010 / 433 + 3)][(100010 / 433 + 3)];
int b[100010], ans, k;
void ins(int v) {
  b[v]++;
  if (b[v] <= k) ans++;
}
int pl, pr;
void add(int v) {
  b[v]++;
  if (b[v] + f[pr][v] - f[pl - 1][v] <= k) ans++;
}
int main() {
  int n, q, m = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), m = max(m, a[i]);
  for (int i = 0; i <= n; i++) fl[i] = n + 1, fr[i] = 0;
  for (int i = 1; i <= n; i++)
    bl[i] = (i - 1) / 433, fl[bl[i]] = min(fl[bl[i]], i),
    fr[bl[i]] = max(fr[bl[i]], i);
  for (int i = 0; i <= bl[n]; i++)
    for (int j = 1; j <= fr[i]; j++) f[i][a[j]]++;
  for (int i = 0; i <= bl[n]; i++) {
    for (int j = 0; j <= m; j++) b[j] = 0;
    ans = 0;
    for (int j = i; j <= bl[n]; j++) {
      for (int k = fl[j]; k <= fr[j]; k++) ins(b[k]);
      res[i][j] = ans;
    }
  }
  int las = 0;
  scanf("%d", &q);
  for (int j = 0; j <= m; j++) b[j] = 0;
  ans = 0;
  while (q-- > 0) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + las) % n + 1, r = (r + las) % n + 1;
    if (l > r) swap(l, r);
    if (bl[l] >= bl[r] - 1) {
      ans = 0;
      for (int i = l; i <= r; i++) ins(a[i]);
      for (int i = l; i <= r; i++) b[a[i]] = 0;
      printf("%d\n", las = ans);
      continue;
    }
    pl = bl[l] + 1, pr = bl[r] - 1;
    int ml = fl[pl], mr = fr[pr];
    ans = res[pl][pr];
    while (ml >= l) add(a[--ml]);
    while (mr <= r) add(a[++mr]);
    printf("%d\n", las = ans);
    while (ml < fl[pl]) b[a[ml++]] = 0;
    while (mr > fr[pr]) b[a[mr--]] = 0;
  }
  return 0;
}
