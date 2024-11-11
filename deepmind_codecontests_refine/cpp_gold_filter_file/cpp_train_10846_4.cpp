#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
long long k, m, n;
long long a[200010], num[200010], sum[200010];
signed main() {
  n = read();
  for (register long long i = 1; i <= n; i++) {
    a[i] = read();
    long long x = a[i];
    while (!(x & 1)) {
      x >>= 1;
      num[i]++;
    }
    sum[num[i]]++;
  }
  long long ans = 0;
  for (register long long i = 1; i <= 20000; i++) {
    if (sum[ans] < sum[i]) ans = i;
  }
  printf("%lld\n", n - sum[ans]);
  for (register long long i = 1; i <= n; i++) {
    if (num[i] != ans) printf("%lld ", a[i]);
  }
  return 0;
}
