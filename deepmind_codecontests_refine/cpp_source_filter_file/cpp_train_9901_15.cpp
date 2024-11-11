#include <bits/stdc++.h>
clock_t t = clock();
namespace my_std {
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
inline T rnd(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}
template <typename T>
inline bool chkmax(T& x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T& x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T& t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
char __sr[1 << 21], __z[20];
int __C = -1, __zz = 0;
inline void Ot() { fwrite(__sr, 1, __C + 1, stdout), __C = -1; }
inline void print(register int x) {
  if (__C > 1 << 20) Ot();
  if (x < 0) __sr[++__C] = '-', x = -x;
  while (__z[++__zz] = x % 10 + 48, x /= 10)
    ;
  while (__sr[++__C] = __z[__zz], --__zz)
    ;
  __sr[++__C] = '\n';
}
void file() {}
inline void chktime() {}
long long ksm(long long x, int y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ret = ret * x;
  return ret;
}
}  // namespace my_std
using namespace my_std;
int n;
int X[303003], Y[303003];
int main() {
  file();
  int Xmax = -1e9, Xmin = 1e9, Ymax = -1e9, Ymin = 1e9, min_XplusY = 1e9,
      max_XminusY = -1e9;
  read(n);
  for (int i = (1); i <= (n); i++)
    read(X[i], Y[i]), chkmax(Xmax, X[i]), chkmin(Xmin, X[i]),
        chkmax(Ymax, Y[i]), chkmin(Ymin, Y[i]), chkmin(min_XplusY, X[i] + Y[i]),
        chkmax(max_XminusY, X[i] - Y[i]);
  int ans = -1e9;
  for (int i = (1); i <= (n); i++)
    chkmax(ans, X[i] + Y[i] - min_XplusY),
        chkmax(ans, Y[i] - X[i] + Xmax - Ymin),
        chkmax(ans, Y[i] + max_XminusY - Xmin),
        chkmax(ans, Y[i] + Xmax - min_XplusY);
  cout << ans * 2 << ' ';
  for (int i = (4); i <= (n); i++)
    printf("%d ", 2 * (Xmax + Ymax - Xmin - Ymin));
  return 0;
}
