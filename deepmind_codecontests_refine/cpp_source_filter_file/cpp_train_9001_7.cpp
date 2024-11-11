#include <bits/stdc++.h>
using namespace std;
int n, q, pos[2000010], r1[2000010], r2[2000010];
long long sum[2000010], a[2000010];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) a[i + n] = a[i];
  for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= q; i++) {
    long long x;
    scanf("%I64d", &x);
    int ans = n;
    memset(pos, 0, sizeof(pos));
    memset(r1, 0, sizeof(r1));
    memset(r2, 0, sizeof(r2));
    pos[1] = 1;
    r2[1] = 1;
    for (int j = 1, tail; j <= 2 * n; j = tail + 1) {
      tail = j;
      while (tail < 2 * n && sum[tail + 1] - sum[j - 1] <= x) ++tail;
      pos[tail + 1] = 1;
      r1[j] = tail;
      r2[tail + 1] = tail + 1;
    }
    for (int j = 1; j <= 2 * n; j++) {
      pos[j] += pos[j - 1];
      r1[j] = max(r1[j], r1[j - 1]);
      r2[j] = max(r2[j], r2[j - 1]);
    }
    for (int j = 1; j <= n; j++) {
      int tail = j + n - 1, p1, p2, now;
      long long s1, s2;
      now = pos[tail] - pos[j - 1];
      if (r1[j] == r1[j - 1]) ++now;
      p1 = r1[j];
      p2 = r2[tail];
      s1 = sum[p1] - sum[j - 1];
      s2 = sum[tail] - sum[p2 - 1];
      if (s1 + s2 <= x) now--;
      ans = min(ans, now);
    }
    printf("%d\n", ans);
  }
  return 0;
}
