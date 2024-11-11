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
const long double eps = 1e-15;
const long double pi = acos(-1);
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long mods = 1e9 + 7;
const long long MAXN = 100005;
const long long INF = 0x7fffffff;
inline long long read() {
  long long f = 1, x = 0;
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
double mx[MAXN], mn[MAXN], smx[MAXN], smn[MAXN], sp[MAXN], sq[MAXN];
signed main() {
  long long n = read();
  for (long long i = 1; i <= n; i++) scanf("%lf", &mx[i]);
  for (long long i = 1; i <= n; i++) scanf("%lf", &mn[i]);
  for (long long i = 1; i <= n; i++) smx[i] = smx[i - 1] + mx[i];
  for (long long i = n; i >= 1; i--) smn[i] = smn[i + 1] + mn[i];
  for (long long i = 1; i <= n; i++) {
    double pl = 1 + smx[i] - smn[i + 1], mul = smx[i],
           mi = sqrt(pl * pl - mul * 4 + eps);
    sp[i] = (pl + mi) * 0.5, sq[i] = (pl - mi) * 0.5;
  }
  for (long long i = 1; i <= n; i++) printf("%.10lf ", sp[i] - sp[i - 1]);
  puts("");
  for (long long i = 1; i <= n; i++) printf("%.10lf ", sq[i] - sq[i - 1]);
  puts("");
  return 0;
}
