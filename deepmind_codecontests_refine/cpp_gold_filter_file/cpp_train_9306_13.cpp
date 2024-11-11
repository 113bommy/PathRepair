#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long w = 1, s = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
long long a[1010];
signed main() {
  long long n = read();
  long long d = read();
  long long res = 0;
  memset(a, 0, sizeof(a));
  for (long long i = 0; i < n; i++) a[i] = read();
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    long long cnt = 0;
    for (long long j = i + 1; a[j] - a[i] <= d && j < n; j++) cnt++;
    res += 2 * cnt;
  }
  printf("%lld\n", res);
  return 0;
}
