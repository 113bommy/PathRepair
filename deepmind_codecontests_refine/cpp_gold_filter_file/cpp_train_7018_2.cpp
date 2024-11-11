#include <bits/stdc++.h>
const int MAXN = 100000;
int a[MAXN + 1], l[MAXN + 1];
long long x;
long long len[MAXN + 1];
int X[MAXN + 1], c[MAXN + 1];
int m, n;
int main() {
  scanf("%ld", &m);
  memset(len, 0, sizeof(len));
  int tt = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%ld", &X[i]);
    if (X[i] == 1) {
      scanf("%ld", &l[i]);
      if (tt < MAXN) {
        tt++;
        a[tt] = l[i];
      }
      len[i] = len[i - 1] + 1;
    } else {
      scanf("%ld%ld", &l[i], &c[i]);
      for (int ii = 1; ii <= c[i]; ii++) {
        for (int jj = 1; jj <= l[i]; jj++) {
          if (tt < MAXN) {
            tt++;
            a[tt] = a[jj];
          } else
            break;
        }
        if (tt == MAXN) break;
      }
      len[i] = len[i - 1] + l[i] * c[i];
    }
  }
  scanf("%ld", &n);
  int h = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &x);
    while (x > len[h]) h++;
    if (X[h] == 1)
      printf("%ld ", l[h]);
    else {
      long long kt = x - len[h - 1];
      printf("%ld ", a[(kt - 1) % l[h] + 1]);
    }
  }
}
