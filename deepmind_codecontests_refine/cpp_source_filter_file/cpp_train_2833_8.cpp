#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const long long N = 505, M = 1e6 + 5, mod = 1e9 + 7;
long long n, m, b[M];
char a[N];
signed main() {
  long long T;
  read(T);
  while (T--) {
    scanf("%d %s", &m, a + 1);
    n = strlen(a + 1);
    long long now = n, len = n;
    for (long long i = 1; i <= n; ++i) b[i] = a[i] - '0';
    for (long long i = 1; i <= m; ++i) {
      long long l = len + 1, r = min(m, i + (now - i) * b[i]);
      for (long long j = l; j <= r; ++j) b[j] = b[j - (now - i)];
      if (len < m) len += (b[i] - 1) * (now - i + mod);
      (now += (b[i] - 1) * (now - i + mod)) %= mod;
    }
    printf("%lld\n", now);
  }
  return 0;
}
