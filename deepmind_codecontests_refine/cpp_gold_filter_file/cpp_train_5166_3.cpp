#include <bits/stdc++.h>
using namespace std;
long long n, m, q, a[100010], b[100010], s[100010], c[100010];
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &q);
  long long i, j;
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (i = 1; i <= m; i++) scanf("%I64d", &b[i]);
  for (i = 1, j = 1, s[0] = 0; i <= n; i++, j *= -1) s[0] += b[i] * j;
  for (i = 1; i <= m - n; i++)
    s[i] = -(s[i - 1] - b[i]) + b[n + i] * (n % 2 ? 1 : -1);
  for (a[0] = 0, i = 1, j = 1; i <= n; i++, j *= -1) a[0] += a[i] * j;
  for (i = 0; i <= m - n; i++) c[i] = a[0] - s[i];
  sort(c, c + m - n + 1);
  long long l, r, x, t = 0, lb, rb, mid, ans;
  for (i = 0; i <= q; i++) {
    if (i) {
      scanf("%I64d%I64d%I64d", &l, &r, &x);
      if (l % 2 && r % 2)
        t += x;
      else if (!(l % 2) && !(r % 2))
        t -= x;
    }
    lb = 0;
    rb = m - n;
    while (lb < rb) {
      mid = (lb + rb) / 2;
      if (c[mid] + t >= 0)
        rb = mid;
      else
        lb = mid + 1;
    }
    ans = abs(c[lb] + t);
    if (lb) ans = min(ans, abs(c[lb - 1] + t));
    printf("%I64d\n", ans);
  }
  return 0;
}
