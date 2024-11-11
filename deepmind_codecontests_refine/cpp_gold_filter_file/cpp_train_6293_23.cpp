#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 1000010, P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int INF = 0xcfcfcfcf;
const long double eps = 1e-9, pi = asin(1) * 2;
inline long long read();
inline int ADD(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int MINUS(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
int n, m, k;
long double fac[N];
inline void init(int n = 1e5) {
  fac[0] = 0;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] + log(i);
}
inline long long read() {
  long long s = 0;
  bool flag = false;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') flag = true;
  for (; '0' <= ch && ch <= '9'; ch = getchar())
    s = (s << 3) + (s << 1) + (ch ^ '0');
  if (flag) return -s;
  return s;
}
int main() {
  init();
  n = read(), m = read(), k = read();
  long double ans = 0;
  for (int r = 0; r <= n; r++)
    for (int c = 0; c <= n; c++) {
      int num = n * (r + c) - r * c;
      if (num <= k)
        ans += exp((fac[n] - fac[r] - fac[(n) - (r)]) +
                   (fac[n] - fac[c] - fac[(n) - (c)]) +
                   (fac[m - num] - fac[k - num] - fac[(m - num) - (k - num)]) -
                   (fac[m] - fac[k] - fac[(m) - (k)]));
      ans = min(ans, (long double)1e99);
    }
  printf("%.10lf\n", (double)ans);
  return 0;
}
