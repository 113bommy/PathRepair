#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const long long MAXN = 2e5 + 10;
long long n;
long long a[MAXN];
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
signed main() {
  long long t = read();
  while (t--) {
    n = read();
    for (long long i = 1; i <= n; i++) {
      a[i] = read();
    }
    long long g = 0;
    for (long long i = 30; i >= 0; i--) {
      long long cnt = 0;
      for (long long j = 1; j <= n; j++) {
        if ((1 << i) & a[j]) {
          cnt++;
        }
      }
      if (cnt) {
        if (!g) {
          g = cnt;
        } else {
          g = gcd(g, cnt);
        }
      }
    }
    if (!g) {
      for (long long i = 1; i <= n; i++) {
        printf("%d ", i);
      }
      puts("");
    } else {
      for (long long i = 1; i * i < g; i++) {
        if (g % i == 0) {
          printf("%d ", i);
        }
      }
      for (long long i = sqrt(g); i; i--) {
        if (g % i == 0) {
          printf("%d ", g / i);
        }
      }
      puts("");
    }
  }
  return 0;
}
