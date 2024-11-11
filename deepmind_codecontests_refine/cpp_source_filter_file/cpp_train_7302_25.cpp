#include <bits/stdc++.h>
using namespace std;
long long a[300005], b[300005], c[300005];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
signed main() {
  long long n = read();
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = read(), b[i] = read();
    long long tp = b[i];
    while (tp) {
      tp >>= 1;
      c[i]++;
    }
    sum += a[i];
  }
  if (sum < 0) {
    for (long long i = 1; i <= n; i++) a[i] = -a[i];
  }
  long long ans = 0;
  for (long long i = 0; i <= 62; i++) {
    long long tmep = 0;
    for (long long j = 1; j <= n; j++) {
      if (c[j] == i + 1) {
        tmep += a[j];
      }
    }
    if (tmep > 0) {
      for (long long j = 1; j <= n; j++) {
        if (b[j] & 1ll << i) {
          a[j] = -a[j];
        }
      }
      ans = ans + 1ll << (i);
    }
  }
  cout << ans;
  return 0;
}
