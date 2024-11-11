#include <bits/stdc++.h>
const long maxn = 200000;
long i, j, k, n, m, b, t;
long x;
long long ans, kao;
long a[maxn], c[maxn];
long son[maxn * 20][2], gs[maxn * 20];
void find(long q, long l, long r, long x, long y) {
  long mid = (l + r) >> 1;
  long i = (x > mid);
  if (l == r) {
    kao = gs[q];
    kao *= y;
    ans += kao;
    return;
  }
  if (gs[q] == 0 || son[q][i] == 0) return;
  if (i)
    find(son[q][1], mid + 1, r, x, y);
  else
    find(son[q][0], l, mid, x, y);
  return;
}
void build(long q, long l, long r, long x, long y) {
  long mid = (l + r) >> 1;
  long i = (x > mid);
  gs[q] += y;
  if (l == r) return;
  if (son[q][i] == 0) son[q][i] = ++t;
  if (i)
    build(son[q][1], mid + 1, r, x, y);
  else
    build(son[q][0], l, mid, x, y);
  return;
}
int main() {
  scanf("%ld%ld%ld", &k, &b, &n);
  if (b >= k || b < 0) {
    puts("0");
    return 0;
  }
  if (b == 0) {
    for (i = 1; i <= n; ++i) {
      scanf("%ld", &x);
      if (x == 0) {
        ++j;
      } else {
        kao = j;
        kao *= j - 1;
        kao /= 2;
        kao += j;
        ans += kao;
        j = 0;
      }
    }
    if (j) {
      kao = j;
      kao *= j - 1;
      kao /= 2;
      kao += j;
      ans += kao;
    }
    printf("%I64d\n", ans);
    return 0;
  }
  --k;
  b %= k;
  t = 1;
  for (i = 1; i <= n; ++i) {
    scanf("%ld", &a[i]);
    if (a[i] == 0) {
      --i;
      --n;
      ++c[i];
    }
  }
  build(1, 0, k, 0, c[0] + 1);
  for (i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
    a[i] %= k;
    find(1, 0, k, (a[i] - b + k) % k, c[i] + 1);
    build(1, 0, k, a[i], c[i] + 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
