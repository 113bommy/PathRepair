#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 998244353;
const int MAXN = 600005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long double fac[MAXN];
inline long double C(int x, int y) { return fac[x] - fac[y] - fac[x - y]; }
inline void Init(int n) {
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] + log(1.0 * i);
}
int main() {
  int n = read(), m = read(), k = read();
  Init(m);
  long double ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      int t = (i + j) * n - i * j;
      if (k - t >= 0) {
        long double p = C(n, i) + C(n, j) + C(m - t, k - t) - C(m, k);
        ans = min((long double)1e99, ans + exp(p));
      }
    }
  printf("%.10Lf\n", ans);
  return 0;
}
