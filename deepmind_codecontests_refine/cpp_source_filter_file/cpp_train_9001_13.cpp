#include <bits/stdc++.h>
using namespace std;
int a[3000000], s[1000000];
int main() {
  int q, w, e, o, c, v, sh, sh1, ans;
  long long r, t, y = 0;
  scanf("%d%d", &q, &o);
  for (w = 0; w < q; w++) {
    scanf("%d", &a[w]);
    y += a[w];
  }
  for (w = q, c = q * 3; w < c; w++) a[w] = a[w - q];
  for (; o; o--) {
    scanf("%I64d", &t);
    if (t >= y) {
      printf("1\n");
      continue;
    }
    r = 0;
    for (e = 0; r + a[e] <= t; e++) r += a[e];
    s[0] = e;
    sh = 0;
    c = sh1 = e;
    for (w = 1; w < (q << 1); w++) {
      r -= a[w - 1];
      c--;
      while (r + a[e] <= t) {
        r += a[e];
        e++;
        c++;
      }
      s[w] = e;
      if (sh1 > c) {
        sh = w;
        sh1 = c;
      }
    }
    ans = 1 << 30;
    for (w = 0; w < sh1; w++) {
      e = sh + w;
      if (e >= q) e -= q;
      c = 0;
      for (v = e; v < q + e; v = s[v]) c++;
      if (v == s[e] + q) c--;
      ans = min(ans, c);
    }
    printf("%d\n", ans);
  }
  return 0;
}
