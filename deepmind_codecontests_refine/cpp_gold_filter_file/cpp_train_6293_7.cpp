#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long double fac[100005];
void Init(int N) {
  fac[0] = log(1.0);
  for (register int i = 1; i <= N; ++i) fac[i] = fac[i - 1] + log(i * 1.0);
}
long double C(int n, int m) { return fac[n] - fac[m] - fac[n - m]; }
int read() {
  int x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('\n');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
signed main() {
  n = read(), m = read(), k = read();
  Init(m);
  long double Ans = 0.0;
  for (register int i = 0; i <= n; ++i)
    for (register int j = 0; j <= n; ++j) {
      int num = (i + j) * n - i * j;
      if (num <= k) {
        long double now = C(n, i) + C(n, j) + C(m - num, k - num) - C(m, k);
        Ans += exp(now);
      }
    }
  if (Ans <= 1e99)
    printf("%.10lf\n", (double)Ans);
  else
    puts("1e99");
  return 0;
}
