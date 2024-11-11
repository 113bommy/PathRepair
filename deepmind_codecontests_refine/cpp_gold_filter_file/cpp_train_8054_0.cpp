#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 7;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const int iv2 = 5e8 + 4;
inline int pls(int x, int y) { return (x + y) % mod; }
inline int mns(int x, int y) { return pls(x, mod - y); }
inline int mul(int x, int y) { return 1LL * x * y % mod; }
inline void Add(int &x, int y) { x = pls(x, y); }
inline void Mul(int &x, int y) { x = mul(x, y); }
inline void Minus(int &x, int y) { x = mns(x, y); }
inline int pwr(int x, int tms) {
  int res = 1;
  for (; tms > 0; tms >>= 1) {
    if (tms & 1) Mul(res, x);
    Mul(x, x);
  }
  return res;
}
inline int inv(int x) { return pwr(x, mod - 2); }
template <class T>
inline T rd() {
  bool f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 0;
  T x = 0;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return f ? x : -x;
}
int P, n, m;
long long bg[maxN];
int sg[maxN];
int cnt[3];
int fac[maxN], ifac[maxN], iv[maxN];
inline int mex(int x, int y) {
  for (int d = (0), _ = (3); d <= _; ++d)
    if (x != d && y != d) return d;
  puts("?");
  return -1;
}
inline int calc(int x, int y) {
  return mns(mul(y - x + 1, P + 1), mul(mul(pls(x, y), y - x + 1), iv[2]));
}
inline int C(int x, int y) {
  return (y <= x) ? mul(mul(fac[x], ifac[y]), ifac[x - y]) : 0;
}
inline int C3(int x, int y, int z) {
  return mul(mul(mul(fac[x + y + z], ifac[x]), ifac[y]), ifac[z]);
}
int main() {
  n = rd<int>(), P = rd<int>() - 1;
  if (P <= 2) {
    puts("0");
    return 0;
  }
  bg[1] = 1, bg[2] = 3, bg[3] = 4;
  m = 3;
  sg[1] = 0, sg[2] = 1, sg[3] = 2;
  int l = 1, r = 2;
  while (1) {
    long long nl = bg[l + 1], nr = r < m ? bg[r + 1] : INF;
    long long tl = 3 * nl, tr = nr * 3 / 2;
    for (int i = max(tr - 20, 1LL); i <= tr + 20; ++i)
      if (i - i / 3 >= nr) {
        tr = i;
        break;
      }
    if (min(tl, tr) > P) break;
    if (tl < tr) {
      int tp = mex(sg[++l], sg[r]);
      if (tp == sg[m]) continue;
      bg[++m] = tl;
      sg[m] = tp;
    } else {
      int tp = mex(sg[l], sg[++r]);
      if (tp == sg[m]) continue;
      bg[++m] = tr;
      sg[m] = tp;
    }
  }
  bg[++m] = P + 1;
  iv[1] = 1;
  for (int i = (2), _ = (n + 1); i <= _; ++i)
    iv[i] = mul(iv[mod % i], mod - mod / i);
  fac[0] = 1;
  for (int i = (1), _ = (n); i <= _; ++i) fac[i] = mul(fac[i - 1], i);
  ifac[0] = 1;
  for (int i = (1), _ = (n); i <= _; ++i) ifac[i] = mul(ifac[i - 1], iv[i]);
  for (int i = (1), _ = (m); i < _; ++i)
    Add(cnt[sg[i]], calc(bg[i], bg[i + 1] - 1));
  int res = pwr(pls(pls(cnt[0], cnt[1]), cnt[2]), n);
  for (int i = 0; i <= n; i += 2)
    for (int j = 0; j + i <= n; j += 2)
      Minus(res, mul(mul(mul(C3(i, j, n - i - j), pwr(cnt[0], n - i - j)),
                         pwr(cnt[1], i)),
                     pwr(cnt[2], j)));
  printf("%d\n", res);
  return 0;
}
