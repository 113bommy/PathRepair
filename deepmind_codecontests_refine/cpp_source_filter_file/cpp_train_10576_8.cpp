#include <bits/stdc++.h>
int n, k, a[2210], b[2210], s[2210], va[2210], vb[2210];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  b[n] = 1 << 30;
  long long ans = 0;
  while (k--) {
    int ra = -1, rb;
    for (int i = n, j = n, pb = n; i--;) {
      if (b[j > i ? j = i : 1] < b[pb] && !vb[j]) pb = j;
      while (j && s[j - 1])
        if (b[--j] < b[pb] && !vb[j]) pb = j;
      if (!va[i] && (ra < 0 || a[i] + b[pb] < a[ra] + b[rb])) ra = i, rb = pb;
    }
    ans += a[ra] + b[rb];
    va[ra]++;
    vb[rb]++;
    for (int i = ra; i < rb; i++) s[i]++;
    for (int i = rb; i < ra; i++) s[i]--;
  }
  printf("%lld\n", ans);
}
