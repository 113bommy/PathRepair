#include <bits/stdc++.h>
struct interval {
  int s, e;
} iv[150];
int a[110];
int c[110];
int u[110];
int v[110];
int main() {
  int l, b, f;
  scanf("%d %d %d", &l, &f, &b);
  int n;
  scanf("%d", &n);
  iv[0].s = 0;
  iv[0].e = l;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    int t;
    int j;
    scanf("%d %d", &t, &a[i]);
    if (t == 1) {
      int x, y;
      for (j = 0; j < cur; j++) {
        if (iv[j].s)
          x = f;
        else
          x = 0;
        if (iv[j].e < l)
          y = b;
        else
          y = 0;
        if (iv[j].e - iv[j].s >= a[i] + x + y) break;
      }
      u[i] = x;
      v[i] = y;
      if (j < cur) {
        c[i] = x + iv[j].s;
        iv[j].s = c[i] + a[i];
        printf("%d\n", c[i]);
      } else
        printf("-1\n");
    } else {
      int m = a[i] - 1;
      for (j = 0; j < cur; j++)
        if (iv[j].s > c[m]) break;
      if (j < cur && iv[j].s == c[m] + a[m]) {
        iv[j].s = c[m] - u[m];
        if (j - 1 >= 0 && iv[j - 1].e == iv[j].s) {
          iv[j - 1].e = iv[j].e;
          for (int k = j; k < cur - 1; k++) iv[k] = iv[k + 1];
          cur--;
          continue;
        }
        continue;
      }
      if (j - 1 >= 0 && iv[j - 1].e == c[m]) {
        iv[j - 1].e = c[m] + a[m] + f;
        if (iv[j - 1].e > l) iv[j - 1].e = l;
        continue;
      }
      struct interval intvl;
      intvl.s = c[m] - u[m];
      intvl.e = c[m] + a[m] + f;
      if (intvl.e > l) intvl.e = l;
      int k;
      for (k = cur - 1; k >= j; k--) iv[k + 1] = iv[k];
      iv[j] = intvl;
      cur++;
    }
  }
  return 0;
}
