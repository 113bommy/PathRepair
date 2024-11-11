#include <bits/stdc++.h>
using namespace std;
struct node {
  char b[13];
} a[13];
int main() {
  int p[13], n, k, i, j, xx, ii, l, r, ans, mmin, mmax, te, jj;
  while (~scanf("%d%d", &n, &k)) {
    for (i = 0; i < n; i++) scanf("%s", a[i].b);
    for (xx = 1, i = 2; i <= k; i++) xx *= i;
    for (i = 0; i < k; i++) p[i] = i;
    for (ans = 1000000000, ii = 0; ii < xx; ii++) {
      for (i = k - 2; i >= 0; i--)
        if (p[i] < p[i + 1]) break;
      for (j = i + 1; j < k; j++)
        if (p[i] > p[j]) break;
      j--;
      jj = p[i], p[i] = p[j], p[j] = jj;
      for (l = i + 1, r = k - 1; l < r; l++, r--)
        jj = p[l], p[l] = p[r], p[r] = jj;
      for (mmin = 1000000000, mmax = -1, i = 0; i < n; i++) {
        for (te = 0, j = 0; j < k; j++) te = 10 * te + a[i].b[p[j]] - '0';
        if (te < mmin) mmin = te;
        if (te > mmax) mmax = te;
      }
      if (mmax - mmin < ans) ans = mmax - mmin;
    }
    printf("%d\n", ans);
  }
  return 0;
}
