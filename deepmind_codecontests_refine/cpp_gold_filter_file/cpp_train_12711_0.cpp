#include <bits/stdc++.h>
const int N = 2097155;
char s[N], t[N];
int n, cnt[N], all;
unsigned long long a[N], b[N];
int main() {
  scanf("%d%s%s", &n, s, t);
  all = (1 << n);
  for (register int i = 1; i <= all - 1; i++) cnt[i] = cnt[i >> 1] + (i & 1);
  for (register int i = 0; i <= all - 1; i++)
    a[i] = (1LL * s[i] - '0') << (cnt[i] * 2), b[i] = (1LL * t[i] - '0')
                                                      << (cnt[i] * 2);
  for (register int j = 0; j <= n - 1; j++)
    for (register int i = 0; i <= all - 1; i++)
      if ((i >> j) & 1) a[i] += a[i ^ (1 << j)], b[i] += b[i ^ (1 << j)];
  for (register int i = 0; i <= all - 1; i++) a[i] *= b[i];
  for (register int j = 0; j <= n - 1; j++)
    for (register int i = 0; i <= all - 1; i++)
      a[i] = ((i >> j) & 1) ? a[i] - a[i ^ (1 << j)] : a[i];
  for (register int i = 0; i <= all - 1; i++)
    printf("%c", '0' + ((a[i] >> (cnt[i] * 2)) & 3));
  return 0;
}
