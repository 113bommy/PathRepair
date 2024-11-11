#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    static int dd[5000 + 1], kk[5000];
    int n, s, lower, upper, diff, i, d, h, l, r;
    scanf("%d%d", &n, &s);
    lower = 0, upper = n * (n - 1) / 2;
    memset(kk, 0, n * sizeof *kk);
    dd[1] = 0;
    kk[0]++;
    for (i = 2; i <= n; i++) {
      dd[i] = dd[i / 2] + 1;
      lower += dd[i];
      kk[dd[i]]++;
    }
    if (s < lower || upper < s) {
      printf("NO\n");
      continue;
    }
    diff = s - lower;
    h = n - 1;
    while (kk[h] == 0) h--;
    d = h++;
    while (diff > 0) {
      int d_;
      while (kk[d] == 1) d--;
      d_ = d;
      while (d_ < h && diff > 0) {
        kk[d_]--, kk[d_ + 1]++;
        d_++;
        diff--;
      }
      if (d_ == h) h++;
    }
    printf("YES\n");
    l = 0, r = 1;
    for (d = 1; d < n; d++) {
      for (i = 0; i < kk[d]; i++) printf("%d ", l + i / 2 + 1);
      l = r, r += kk[d];
    }
    printf("\n");
  }
  return 0;
}
