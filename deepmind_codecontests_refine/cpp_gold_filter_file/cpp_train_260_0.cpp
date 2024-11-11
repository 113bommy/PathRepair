#include <bits/stdc++.h>
const int N = 2000005;
long long a[N], b[N], c[N];
char s[N];
int read() {
  int x = 0, v = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; v = (ch == '-') ? (-1) : (v), ch = getchar())
    ;
  for (; ch <= '9' && ch >= '0'; x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * v;
}
void FWT(long long *a, int n, int f) {
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += (i << 1)) {
      for (int k = 0; k < i; ++k) {
        long long u = a[j + k], v = a[j + k + i];
        a[j + k] = u + v, a[j + k + i] = u - v;
        if (f == -1) a[j + k] /= 2, a[j + k + i] /= 2;
      }
    }
  }
}
int main(void) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++j) {
      a[j] |= ((s[j] - '0') << i - 1);
    }
  }
  for (int i = 1; i <= m; ++i) b[a[i]]++;
  for (int i = 0; i <= (1 << n) - 1; ++i) c[i] = c[i >> 1] + (i & 1);
  for (int i = 0; i <= (1 << n) - 1; ++i) c[i] = std::min(c[i], n - c[i]);
  FWT(b, (1 << n), 1);
  FWT(c, (1 << n), 1);
  for (int i = 0; i <= (1 << n) - 1; ++i) b[i] *= c[i];
  FWT(b, (1 << n), -1);
  long long ans = 8000000;
  for (int i = 0; i <= (1 << n) - 1; ++i) ans = std::min(ans, b[i]);
  printf("%lld\n", ans);
  return 0;
}
