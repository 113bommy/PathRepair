#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 100;
const long long inf = 0x3f3f3f3f;
const long long iinf = 1 << 30;
const long long linf = 2e18;
const long long mod = 998244353;
const double eps = 1e-7;
template <class T = long long>
T chmin(T &a, T b) {
  return a = min(a, b);
}
template <class T = long long>
T chmax(T &a, T b) {
  return a = max(a, b);
}
template <class T = long long>
inline void red(T &x) {
  x -= mod, x += x >> 31 & mod;
}
template <class T = long long>
T read() {
  T f = 1, a = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    a = (a << 3) + (a << 1) + ch - '0';
    ch = getchar();
  }
  return a * f;
}
long long n;
long long a[maxn], tot;
pair<double, long long> stk[maxn];
signed main() {
  n = read();
  for (long long i = (1); i <= (n); ++i) a[i] = read();
  for (long long i = (n); i >= (1); --i) {
    long long len = 1;
    double all = a[i];
    while (tot && stk[tot].first <= all / len)
      all += stk[tot].first * stk[tot].second, len += stk[tot].second, --tot;
    stk[++tot] = make_pair(all / len, len);
  }
  for (long long i = (tot); i >= (1); --i)
    for (long long j = (1); j <= (stk[i].second); ++j)
      printf("%.10lf\n", stk[i].first);
  return 0;
}
