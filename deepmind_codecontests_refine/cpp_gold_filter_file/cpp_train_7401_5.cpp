#include <bits/stdc++.h>
const long long M = 150005;
long long read() {
  long long num = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
  return num * flag;
}
long long n, k = -1, ma, flag, a[M], b[M];
signed main() {
  n = read();
  for (long long i = 0; i < n; i++) a[i] = read();
  for (long long i = 0; i < n; i++) {
    if (a[i] > 0) flag = 1;
    if (ma < a[i] && a[i] > a[(i - 1 + n) % n]) {
      ma = a[i];
      k = i;
    }
  }
  if (!flag) {
    puts("YES");
    for (long long i = 0; i < n; i++) printf("1 ");
    return 0;
  }
  if (k == -1) {
    puts("NO");
    return 0;
  }
  b[k] = a[k];
  k = (k - 1 + n) % n;
  b[k] = b[(k + 1) % n] * 2 + a[k];
  for (long long i = 1; i < n - 1; i++) {
    k = (k - 1 + n) % n;
    b[k] = b[(k + 1) % n] + a[k];
  }
  puts("YES");
  for (long long i = 0; i < n; i++) printf("%lld ", b[i]);
}
