#include <bits/stdc++.h>
#pragma optimize("avx")
#pragma optimize("no-stack-protector")
namespace io {
inline char gnc() { return (char)getchar(); }
template <typename T>
inline void gi(T &dx) {
  dx = 0;
  int yc = gnc();
  bool nega = false;
  while (yc < '0' || yc > '9') {
    nega = (yc == '-' ? true : nega);
    yc = gnc();
  }
  while (yc >= '0' && yc <= '9') {
    dx = (T)(dx * 10 + yc - '0');
    yc = gnc();
  }
  if (nega) {
    dx = -dx;
  }
}
void gc(char &a) {
  do a = gnc();
  while (!isgraph(a));
}
void gss(char *c) {
  *c = gnc();
  while (!isgraph(*c)) *c = gnc();
  while (isgraph(*c)) *++c = gnc();
  *c = 0;
}
template <typename t1, typename t2>
inline void gi(t1 &a, t2 &b) {
  gi(a);
  gi(b);
}
template <typename t1, typename t2, typename t3>
inline void gi(t1 &a, t2 &b, t3 &c) {
  gi(a);
  gi(b);
  gi(c);
}
template <typename t1, typename t2, typename t3, typename t4>
inline void gi(t1 &a, t2 &b, t3 &c, t4 &d) {
  gi(a);
  gi(b);
  gi(c);
  gi(d);
}
template <typename t1, typename t2, typename t3, typename t4, typename t5>
inline void gi(t1 &a, t2 &b, t3 &c, t4 &d, t5 &e) {
  gi(a);
  gi(b);
  gi(c);
  gi(d);
  gi(e);
}
}  // namespace io
using namespace io;
using namespace std;
inline int gcd(int x, int y) {
  return y > x ? gcd(y, x) : y ? gcd(y, x % y) : x;
}
inline void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
}
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int Rev = (MOD + 1) >> 1;
template <typename T>
inline void Sol(T &x) {
  if (x >= MOD) x -= MOD;
}
template <typename t1, typename t2>
inline int inc(t1 x, t2 y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
template <typename t1, typename t2>
inline int dec(t1 x, t2 y) {
  x += MOD - y;
  if (x >= MOD) x -= MOD;
  return x;
}
template <typename t1, typename t2>
inline long long mul(t1 x, t2 y) {
  long long res = (long long)x * y;
  return res >= MOD ? res % MOD : res;
}
template <typename t1, typename t2, typename t3>
inline long long mul(t1 x, t2 y, t3 z) {
  return mul(mul(x, y), z);
}
template <typename t1, typename t2, typename t3, typename t4>
inline long long mul(t1 a, t2 b, t3 c, t4 d) {
  return mul(mul(a, b), mul(c, d));
}
inline long long qpow(long long x, int y) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x % MOD)
    if (y & 1) res = res * x % MOD;
  return res;
}
inline long long read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
template <typename T1, typename T2>
inline void Getmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void Getmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
const int MAXN = 52;
int n, d[MAXN], f[2][MAXN][MAXN][MAXN][MAXN];
inline long long binom(long long x) { return 1LL * x * (x - 1) / 2ll % MOD; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) d[i] = read();
  int np = 0;
  f[np][d[1] == 2][d[1] == 3][d[2] == 2][d[2] == 3] = 1;
  for (int i = 3; i <= n; i++) {
    int p = np, op = d[i] & 1;
    np ^= 1;
    memset(f[np], 0, sizeof f[np]);
    for (int pre1 = 0; pre1 < i; pre1++)
      for (int pre2 = 0; pre2 < i - pre1; pre2++) {
        int now1up = i - pre1 - pre2, now2up;
        for (int now1 = 0; now1 < now1up; now1++) {
          now2up = now1up - now1;
          for (int now2 = 0; now2 < now2up; now2++)
            if (f[p][pre1][pre2][now1][now2]) {
              if (!(now1 || now2 || pre1 || pre2)) continue;
              int val = f[p][pre1][pre2][now1][now2];
              if (!pre1 && !pre2) {
                if (now1)
                  f[np][now1 - 1][now2][op ^ 1][op] =
                      inc(f[np][now1 - 1][now2][op ^ 1][op], mul(val, now1));
                if (now2)
                  f[np][now1 + 1][now2 - 1][op ^ 1][op] = inc(
                      f[np][now1 + 1][now2 - 1][op ^ 1][op], mul(val, now2));
              } else {
                if (pre1) {
                  int newnow1 = now1 + (op ^ 1), newnow2 = now2 + op;
                  long long v = mul(val, pre1);
                  int newpre1 = pre1 - 1;
                  f[np][newpre1][pre2][newnow1][newnow2] =
                      inc(f[np][newpre1][pre2][newnow1][newnow2], v);
                  if (now1) {
                    f[np][newpre1][pre2][now1 - 1 + op][now2] =
                        inc(f[np][newpre1][pre2][now1 - 1 + op][now2],
                            mul(v, now1));
                    if (op && now1 > 1)
                      f[np][newpre1][pre2][now1 - 2][now2] =
                          inc(f[np][newpre1][pre2][now1 - 2][now2],
                              mul(v, binom(now1)));
                  }
                  if (now2) {
                    f[np][newpre1][pre2][now1 + op + 1][now2 - 1] =
                        inc(f[np][newpre1][pre2][now1 + op + 1][now2 - 1],
                            mul(v, now2));
                    if (op && now2 > 1)
                      f[np][newpre1][pre2][now1 + 2][now2 - 2] =
                          inc(f[np][newpre1][pre2][now1 + 2][now2 - 2],
                              mul(v, binom(now2)));
                  }
                  if (now1 && now2 && op)
                    f[np][newpre1][pre2][now1][now2 - 1] =
                        inc(f[np][newpre1][pre2][now1][now2 - 1],
                            mul(mul(v, now1), now2));
                }
                if (pre2) {
                  int newnow1 = now1 + (op ^ 1), newnow2 = now2 + op;
                  long long v = mul(val, pre2);
                  int newpre1 = pre1 + 1, newpre2 = pre2 - 1;
                  f[np][newpre1][newpre2][newnow1][newnow2] =
                      inc(f[np][newpre1][newpre2][newnow1][newnow2], v);
                  if (now1) {
                    f[np][newpre1][newpre2][now1 - 1 + op][now2] =
                        inc(f[np][newpre1][newpre2][now1 - 1 + op][now2],
                            mul(v, now1));
                    if (op && now1 > 1)
                      f[np][newpre1][newpre2][now1 - 2][now2] =
                          inc(f[np][newpre1][newpre2][now1 - 2][now2],
                              mul(v, binom(now1)));
                  }
                  if (now2) {
                    f[np][newpre1][newpre2][now1 + op + 1][now2 - 1] =
                        inc(f[np][newpre1][newpre2][now1 + op + 1][now2 - 1],
                            mul(v, now2));
                    if (op && now2 > 1)
                      f[np][newpre1][newpre2][now1 + 2][now2 - 2] =
                          inc(f[np][newpre1][newpre2][now1 + 2][now2 - 2],
                              mul(v, binom(now2)));
                  }
                  if (now1 && now2 && op)
                    f[np][newpre1][newpre2][now1][now2 - 1] =
                        inc(f[np][newpre1][newpre2][now1][now2 - 1],
                            mul(v, now1, now2));
                }
              }
            }
        }
      }
  }
  int ans = f[n & 1][0][0][0][0];
  printf("%d\n", ans);
  return 0;
}
