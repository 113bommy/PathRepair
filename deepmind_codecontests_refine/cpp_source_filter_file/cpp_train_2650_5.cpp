#include <bits/stdc++.h>
int main() {
  long long l, r, k, m = 1e9, c, s, n;
  scanf("%I64d%I64d%I64d", &l, &r, &k);
  n = r - l + 1;
  if (n <= 4) {
    for (long long i = 1; i < 1 << n; i++) {
      long long v, cnt = 0, first = 1;
      for (long long j = 0; j < n; j++)
        if (i & (1 << j)) {
          if (first)
            v = (l + j), first = 0;
          else
            v ^= (l + j);
          cnt++;
        }
      if (cnt <= k && v < m) m = v, c = cnt, s = i;
    }
  } else if (k == 1)
    m = l, c = 1, s = 1;
  else if (k == 2)
    l % 2 ? (m = 1, c = 2, s = 6) : (m = 1, c = 2, s = 3);
  else if (k == 3) {
    long long z, y, x = 1;
    for (; x < l; x = x << 1 | 1)
      ;
    y = (x + 1) | (x >> 1), z = (x + 1) | (x + 1 >> 1);
    if (z <= r) {
      printf("0\n3\n%I64d %I64d %I64d\n", x, y, z);
      return 0;
    } else
      l % 2 ? (m = 1, c = 2, s = 6) : (m = 1, c = 2, s = 3);
  } else
    l % 2 ? (m = 0, c = 4, s = 30) : (m = 0, c = 4, s = 15);
  printf("%I64d\n%I64d\n", m, c);
  long long first = 1;
  for (long long i = 0; i < n; i++) {
    if (s & (1 << i)) {
      if (first)
        first = 0, printf("%I64d", l + i);
      else
        printf(" %I64d", l + i);
      if (!(--c)) break;
    }
  }
  puts("");
  return 0;
}
