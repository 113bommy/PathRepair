#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
;
const double pi = acos(-1.0);
template <class T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
};
const int mo = 1000000009, maxn = 5000;
long long ans;
int n, a, b, inv[maxn], fac[maxn], f[maxn], g[maxn];
int C(int n, int m) {
  if (n == 0) return 1;
  if (n < m) return 0;
  long long ret = fac[n];
  ret = ret * inv[m] % mo;
  ret = ret * inv[n - m] % mo;
  return int(ret);
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  fac[0] = 1;
  for (int i = (1); i <= (4000); ++i) fac[i] = (long long)fac[i - 1] * i % mo;
  for (int i = (0); i <= (4000); ++i) inv[i] = Pow(fac[i], mo - 2, mo);
  for (int i = (1); i <= (n); ++i) f[i] = C(a - 1, i - 1);
  for (int i = (1); i <= (n); ++i) g[i] = C(b - 1, i - 1);
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n - 1); ++j) {
      ans += (long long)f[i + n - j] * g[j - i] % mo;
      ans %= mo;
    }
  ans = ans * fac[a] % mo * fac[b] % mo;
  printf("%lld\n", ans);
  return 0;
}
