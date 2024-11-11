#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T Read(T Type) {
  T x = 0, f = 1;
  char a = getchar();
  while (!('0' <= (a) && (a) <= '9')) {
    if (a == '-') f = -1;
    a = getchar();
  }
  while (('0' <= (a) && (a) <= '9')) {
    x = (x << 1) + (x << 3) + (a ^ '0');
    a = getchar();
  }
  return x * f;
}
const int MAXN = 100010;
long double f[MAXN], ans;
inline long double C(int n, int m) { return f[n] - f[m] - f[n - m]; }
int main() {
  int n = Read(1), m = Read(1), k = Read(1);
  for (register int i = 1; i <= 1e5; i++) f[i] = f[i - 1] + log(1.0 * i);
  for (register int i = 0; i <= n; i++) {
    for (register int j = 0; j <= n; j++) {
      int num = (i + j) * n - i * j;
      if (num <= k) {
        long double p = C(n, i) + C(n, j) + C(m - num, k - num) - C(m, k);
        ans = min(ans + exp(p), (long double)1e99);
      }
    }
  }
  printf("%.10lf", (double)ans);
  return 0;
}
