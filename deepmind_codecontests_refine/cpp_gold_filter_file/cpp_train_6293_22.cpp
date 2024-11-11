#include <bits/stdc++.h>
using namespace std;
inline int ci() {
  register char ch;
  int f = 1;
  while (!isdigit(ch = getchar())) f = ch == '-' ? -1 : 1;
  register int x = ch ^ '0';
  while (isdigit(ch = getchar())) x = (x * 10) + (ch ^ '0');
  return f * x;
}
enum { N = 100023 };
long double fac[N];
inline void init_fac(int n) {
  fac[0] = log(1);
  for (register int i = (1); i <= (n); i++) fac[i] = fac[i - 1] + log(i);
}
inline long double comp(long long n, long long m) {
  return fac[n] - fac[m] - fac[n - m];
}
int main() {
  int n = ci(), m = ci(), k = ci();
  init_fac(m);
  long double ans = 0;
  for (register int i = (0); i <= (n); i++) {
    for (register int j = (0); j <= (n); j++) {
      long long cnt = (i + j) * n - i * j;
      if (k - cnt < 0) continue;
      long double x =
          comp(n, i) + comp(n, j) + comp(m - cnt, k - cnt) - comp(m, k);
      ans = min(ans + exp(x), (long double)1e99);
    }
  }
  printf("%.10lf\n", (double)ans);
  return 0;
}
